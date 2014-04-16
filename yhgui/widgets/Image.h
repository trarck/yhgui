#ifndef YHGUI_WIDGETS_IMAGE_H_
#define YHGUI_WIDGETS_IMAGE_H_

#include "cocos2d.h"
#include "../Component.h"

NS_CC_YHGUI_BEGIN

class ImageSprite : public CCSprite
{
public:
    
    ImageSprite();
    
    virtual void setTextureRect(const CCRect& rect);
    
    virtual void setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize);
    
    
public:
    
    enum FillType
    {
        kNormal,//keep texture original size
        kScale,//resize texture
        kClip,//clip texture
    };
    
    inline void setPreferredSize(const CCSize& preferredSize)
    {
        m_preferredSize = preferredSize;
        m_havePreferredSize=true;
        
        //如果已经设置texture，则调整texture
        if(m_pobTexture){
            adjustTextureRect();
        }
    }
    
    inline const CCSize& getPreferredSize()
    {
        return m_preferredSize;
    }
    
    inline void setUntrimmedSize(const CCSize& untrimmedSize)
    {
        m_untrimmedSize = untrimmedSize;
    }
    
    inline const CCSize& getUntrimmedSize()
    {
        return m_untrimmedSize;
    }
    
    inline void setFillType(int fillType)
    {
        m_fillType = fillType;
    }
    
    inline int getFillType()
    {
        return m_fillType;
    }
    
protected:
    
    void adjustTextureRect();
    
    void adjustTextureByScale();
    
    void adjustTextureByClip();
    
protected:
    
    CCSize m_preferredSize;
    
    bool m_havePreferredSize;
    
    CCSize m_untrimmedSize;
    
    int m_fillType;
    
    CCRect m_orignalRect;
};

class Image:public Component
{
public:
    
    Image();
    
    ~Image();
    
    bool init();
    
    bool init(CCTexture2D *pTexture);
    
    bool init(CCTexture2D *pTexture, const CCRect& rect);
    
    bool init(CCTexture2D *pTexture, const CCRect& rect, bool rotated);
    
    bool initWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
    virtual bool initWithFile(const char *pszFilename);
    
    virtual bool initWithFile(const char *pszFilename, const CCRect& rect);
    
    
    void setTexture(CCTexture2D *texture);
    
    inline CCTexture2D* getTexture(void)
    {
        return m_renderer->getTexture();
    }
    
    inline void setBlendFunc(ccBlendFunc blendFunc) { m_renderer->setBlendFunc(blendFunc); }
    
    void setTexParams(const ccTexParams& texParams);
    
    void setWrapMode(unsigned int wraps,unsigned int wrapt);
    
    virtual void setContentSize(const CCSize& contentSize);

public:
    
    inline const ccTexParams& getTexParams()
    {
        return m_texParams;
    }
    
protected:
    
    inline void initTexParams()
    {
        m_texParams.minFilter=GL_LINEAR;
        m_texParams.magFilter=GL_LINEAR;
        m_texParams.wrapS=GL_CLAMP_TO_EDGE;
        m_texParams.wrapT=GL_CLAMP_TO_EDGE;
    }
    
protected:

    ImageSprite* m_renderer;
    
    ccTexParams m_texParams;
    
    bool m_texParamsDirty;
    
};


NS_CC_YHGUI_END

#endif // YHGUI_WIDGETS_IMAGE_H_
