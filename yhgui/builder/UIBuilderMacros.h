//
//  UIBuilder.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_UIBUILDERMACROS_H_
#define COCOS_YHGUI_BUILDER_UIBUILDERMACROS_H_

#define YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(T) virtual T * create(const yhge::Json::Value& defineData) { \
return T::create(); \
}

#define YHGUI_PURE_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(T) virtual T * create(const yhge::Json::Value& defineData) = 0

#define YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(T, METHOD) static T * METHOD() { \
    T * ptr = new T(); \
    if(ptr != NULL) { \
        ptr->autorelease(); \
        return ptr; \
    } \
    CC_SAFE_DELETE(ptr); \
    return NULL; \
}

#define YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(T, METHOD) static T * METHOD() { \
    T * ptr = new T(); \
    if(ptr != NULL && ptr->init()) { \
        ptr->autorelease(); \
        return ptr; \
    } \
    CC_SAFE_DELETE(ptr); \
    return NULL; \
}

#endif // COCOS_YHGUI_BUILDER_UIBUILDERMACROS_H_
