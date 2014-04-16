#include "Image.h"
#include <yhge/yhge.h>


USING_NS_CC_YHGE;

NS_CC_YHGUI_BEGIN

ImageSprite::ImageSprite()
:m_fillType(kNormal)
,m_preferredSize(CCSizeZero)
,m_havePreferredSize(false)
,m_untrimmedSize(CCSizeZero)
,m_orignalRect(CCRectZero)
{
    
}

void ImageSprite::setTextureRect(const CCRect& rect)
{
    CCSprite::setTextureRect(rect, false, rect.size);
}

void ImageSprite::setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize)
{
    m_orignalRect=rect;
    m_bRectRotated=rotated;
    setUntrimmedSize(untrimmedSize);
    
    if (!m_havePreferredSize) {
        CCSprite::setTextureRect(rect, rotated, untrimmedSize);
    }else{
        adjustTextureRect();
    }
}

void ImageSprite::adjustTextureRect()
{
    switch (m_fillType) {
        case kScale:
            adjustTextureByScale();
            break;
        case kClip:
            adjustTextureByClip();
            break;
        case kNormal:
        default:
//            CCSprite::setTextureRect(m_orignalRect, m_bRectRotated, m_untrimmedSize);
            break;
    }
}

void ImageSprite::adjustTextureByScale()
{
    setContentSize(m_preferredSize);
    
    setTextureCoords(m_orignalRect);
    
    float scaleX=m_preferredSize.width/m_untrimmedSize.width;
    float scaleY=m_preferredSize.height/m_untrimmedSize.height;

    CCRect vertexRect=m_orignalRect;
    vertexRect.size.width*=scaleX;
    vertexRect.size.height*=scaleY;
    setVertexRect(vertexRect);
    
    CCPoint relativeOffset = m_obUnflippedOffsetPositionFromCenter;
    
    // issue #732
    if (m_bFlipX)
    {
        relativeOffset.x = -relativeOffset.x;
    }
    if (m_bFlipY)
    {
        relativeOffset.y = -relativeOffset.y;
    }
    
    m_obOffsetPosition.x = relativeOffset.x + (m_untrimmedSize.width - m_orignalRect.size.width) / 2;
    m_obOffsetPosition.y = relativeOffset.y + (m_untrimmedSize.height - m_orignalRect.size.height) / 2;
    
    m_obOffsetPosition.x*=scaleX;
    m_obOffsetPosition.y*=scaleY;
    
    // rendering using batch node
    if (m_pobBatchNode)
    {
        // update dirty_, don't update recursiveDirty_
        setDirty(true);
    }
    else
    {
        // self rendering
        
        // Atlas: Vertex
        float x1 = 0 + m_obOffsetPosition.x;
        float y1 = 0 + m_obOffsetPosition.y;
        float x2 = x1 + m_obRect.size.width;
        float y2 = y1 + m_obRect.size.height;
        
        // Don't update Z.
        m_sQuad.bl.vertices = vertex3(x1, y1, 0);
        m_sQuad.br.vertices = vertex3(x2, y1, 0);
        m_sQuad.tl.vertices = vertex3(x1, y2, 0);
        m_sQuad.tr.vertices = vertex3(x2, y2, 0);
    }
}

void ImageSprite::adjustTextureByClip()
{
    
    setContentSize(m_preferredSize);
    
    CCRect textureRect=m_orignalRect;
    textureRect.size.width=MIN(textureRect.size.width, m_preferredSize.width);
    textureRect.size.height=MIN(textureRect.size.height, m_preferredSize.height);
    setTextureCoords(textureRect);
    
    CCPoint relativeOffset = m_obUnflippedOffsetPositionFromCenter;
    
    // issue #732
    if (m_bFlipX)
    {
        relativeOffset.x = -relativeOffset.x;
    }
    if (m_bFlipY)
    {
        relativeOffset.y = -relativeOffset.y;
    }
    
    m_obOffsetPosition.x = relativeOffset.x + (m_untrimmedSize.width - m_orignalRect.size.width) / 2;
    
    m_obOffsetPosition.y = relativeOffset.y + (m_untrimmedSize.height - m_orignalRect.size.height) / 2;
    
    //设置要渲染的大小
    CCRect vertexRect=m_orignalRect;
    float vertexWidth=m_preferredSize.width-m_obOffsetPosition.x;
    float vertexHeight=m_preferredSize.height-m_obOffsetPosition.y;
    
    //保证在0和rect.size之间
    vertexWidth=MAX(0, MIN(vertexWidth, m_orignalRect.size.width));
    vertexHeight=MAX(0, MIN(vertexWidth, m_orignalRect.size.height));
    
    vertexRect.size.width=vertexWidth;
    vertexRect.size.height=vertexHeight;
    
    setVertexRect(vertexRect);
    
    // rendering using batch node
    if (m_pobBatchNode)
    {
        // update dirty_, don't update recursiveDirty_
        setDirty(true);
    }
    else
    {
        // self rendering
        
        // Atlas: Vertex
        float x1 = 0 + m_obOffsetPosition.x;
        float y1 = 0 + m_obOffsetPosition.y;
        float x2 = x1 + m_obRect.size.width;
        float y2 = y1 + m_obRect.size.height;
        
        // Don't update Z.
        m_sQuad.bl.vertices = vertex3(x1, y1, 0);
        m_sQuad.br.vertices = vertex3(x2, y1, 0);
        m_sQuad.tl.vertices = vertex3(x1, y2, 0);
        m_sQuad.tr.vertices = vertex3(x2, y2, 0);
    }
}


Image::Image()
:m_renderer(NULL)
,m_texParamsDirty(false)
{
	
}

Image::~Image()
{
	CC_SAFE_RELEASE_NULL(m_renderer);
}

bool Image::init()
{
    return init(CCDefaultTexture::getInstance()->getTexture());
}

bool Image::init(CCTexture2D *pTexture)
{
    if (Component::init()) {
       
        initTexParams();
        
        m_renderer=new ImageSprite();
        m_renderer->initWithTexture(pTexture);
        m_renderer->setFillType(ImageSprite::kScale);
        
        addChild(m_renderer);
        
        return true;
    }
    
    return false;
}

bool Image::init(CCTexture2D *pTexture, const CCRect& rect)
{
    return init(pTexture,rect,false);
}

bool Image::init(CCTexture2D *pTexture, const CCRect& rect, bool rotated)
{
    if (Component::init()) {
        
        initTexParams();
        
        m_renderer=new ImageSprite();
        m_renderer->initWithTexture(pTexture,rect,rotated);
        m_renderer->setFillType(ImageSprite::kScale);
        
        addChild(m_renderer);
        
        return true;
    }
    
    return false;
}

bool Image::initWithSpriteFrame(CCSpriteFrame *pSpriteFrame)
{
    if (Component::init()) {
        
        initTexParams();
        
        m_renderer=new ImageSprite();
        m_renderer->initWithSpriteFrame(pSpriteFrame);
        m_renderer->setFillType(ImageSprite::kScale);
        
        addChild(m_renderer);
        
        return true;
    }
    
    return false;
}

bool Image::initWithFile(const char *pszFilename)
{
    if (Component::init()) {
        
        initTexParams();
        
        m_renderer=new ImageSprite();
        m_renderer->initWithFile(pszFilename);
        m_renderer->setFillType(ImageSprite::kScale);
        
        addChild(m_renderer);
        
        return true;
    }
    
    return false;
}

bool Image::initWithFile(const char *pszFilename, const CCRect& rect)
{
    if (Component::init()) {
        
        initTexParams();
        
        m_renderer=new ImageSprite();
        m_renderer->initWithFile(pszFilename,rect);
        m_renderer->setFillType(ImageSprite::kScale);
        
        addChild(m_renderer);
        
        return true;
    }
    
    return false;
}

void Image::setTexture(CCTexture2D *texture)
{
    if (m_texParamsDirty) {
        texture->setTexParameters(&m_texParams);
    }
    m_renderer->setTexture(texture);
}

void Image::setTexParams(const ccTexParams& texParams)
{
    if (m_texParams.minFilter!=texParams.minFilter
        || m_texParams.magFilter!=texParams.magFilter
        || m_texParams.wrapS!=texParams.wrapS
        || m_texParams.wrapT!=texParams.wrapT) {
        m_texParamsDirty=true;
    }
    
    m_texParams = texParams;
    
    if (m_texParamsDirty) {
        m_renderer->getTexture()->setTexParameters(&m_texParams);
    }
}
void Image::setWrapMode(unsigned int wraps,unsigned int wrapt)
{
    m_texParams.wrapS=wraps;
    m_texParams.wrapT=wrapt;
    
    m_texParamsDirty=true;
    
    m_renderer->getTexture()->setTexParameters(&m_texParams);
}

void Image::setContentSize(const CCSize& contentSize)
{
    Component::setContentSize(contentSize);
    
    //如果图片大小和内容大小不一致，则缩放。
    CCSize spriteSize=m_renderer->getContentSize();
    
    if (spriteSize.width!=contentSize.width || spriteSize.height!=contentSize.height) {
        m_renderer->setPreferredSize(contentSize);
    }
}

NS_CC_YHGUI_END