// Generated by Apple Swift version 5.5 (swiftlang-1300.0.31.1 clang-1300.0.29.1)
#ifndef HYBID_SWIFT_H
#define HYBID_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#import <HyBid.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="HyBid",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


SWIFT_CLASS("_TtC5HyBid24HyBidReportingProperties")
@interface HyBidReportingProperties : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSString;

SWIFT_CLASS_NAMED("AdFormat")
@interface HyBidReportingAdFormat : HyBidReportingProperties
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull NATIVE;)
+ (NSString * _Nonnull)NATIVE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull BANNER;)
+ (NSString * _Nonnull)BANNER SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull FULLSCREEN;)
+ (NSString * _Nonnull)FULLSCREEN SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull REWARDED;)
+ (NSString * _Nonnull)REWARDED SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("Common")
@interface HyBidReportingCommon : HyBidReportingProperties
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_FORMAT;)
+ (NSString * _Nonnull)AD_FORMAT SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_SIZE;)
+ (NSString * _Nonnull)AD_SIZE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CATEGORY_ID;)
+ (NSString * _Nonnull)CATEGORY_ID SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CAMPAIGN_ID;)
+ (NSString * _Nonnull)CAMPAIGN_ID SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull EVENT_TYPE;)
+ (NSString * _Nonnull)EVENT_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CREATIVE_TYPE;)
+ (NSString * _Nonnull)CREATIVE_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull TIMESTAMP;)
+ (NSString * _Nonnull)TIMESTAMP SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull APPTOKEN;)
+ (NSString * _Nonnull)APPTOKEN SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull ZONE_ID;)
+ (NSString * _Nonnull)ZONE_ID SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull INTEGRATION_TYPE;)
+ (NSString * _Nonnull)INTEGRATION_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull KEY_MEDIATION_VENDOR;)
+ (NSString * _Nonnull)KEY_MEDIATION_VENDOR SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull TIME_TO_LOAD;)
+ (NSString * _Nonnull)TIME_TO_LOAD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_TYPE;)
+ (NSString * _Nonnull)AD_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CACHE_TIME;)
+ (NSString * _Nonnull)CACHE_TIME SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_REQUEST;)
+ (NSString * _Nonnull)AD_REQUEST SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_RESPONSE;)
+ (NSString * _Nonnull)AD_RESPONSE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull RESPONSE_TIME;)
+ (NSString * _Nonnull)RESPONSE_TIME SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull REQUEST_TYPE;)
+ (NSString * _Nonnull)REQUEST_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull RENDER_TIME;)
+ (NSString * _Nonnull)RENDER_TIME SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_POSITION;)
+ (NSString * _Nonnull)AD_POSITION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull ERROR_CODE;)
+ (NSString * _Nonnull)ERROR_CODE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull ERROR_MESSAGE;)
+ (NSString * _Nonnull)ERROR_MESSAGE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CREATIVE;)
+ (NSString * _Nonnull)CREATIVE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull HAS_END_CARD;)
+ (NSString * _Nonnull)HAS_END_CARD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull LAST_SESSION_TIMESTAMP;)
+ (NSString * _Nonnull)LAST_SESSION_TIMESTAMP SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull IMPRESSION_SESSION_COUNT;)
+ (NSString * _Nonnull)IMPRESSION_SESSION_COUNT SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull START_SESSION_TIMESTAMP;)
+ (NSString * _Nonnull)START_SESSION_TIMESTAMP SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull SESSION_DURATION;)
+ (NSString * _Nonnull)SESSION_DURATION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AGE_OF_APP;)
+ (NSString * _Nonnull)AGE_OF_APP SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("CreativeType")
@interface HyBidReportingCreativeType : HyBidReportingProperties
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull STANDARD;)
+ (NSString * _Nonnull)STANDARD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO;)
+ (NSString * _Nonnull)VIDEO SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS_NAMED("EventType")
@interface HyBidReportingEventType : HyBidReportingProperties
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull REQUEST;)
+ (NSString * _Nonnull)REQUEST SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull IMPRESSION;)
+ (NSString * _Nonnull)IMPRESSION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull OMID_IMPRESSION;)
+ (NSString * _Nonnull)OMID_IMPRESSION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CLICK;)
+ (NSString * _Nonnull)CLICK SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull ERROR;)
+ (NSString * _Nonnull)ERROR SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull INTERSTITIAL_CLOSED;)
+ (NSString * _Nonnull)INTERSTITIAL_CLOSED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_STARTED;)
+ (NSString * _Nonnull)VIDEO_STARTED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_DISMISSED;)
+ (NSString * _Nonnull)VIDEO_DISMISSED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_FINISHED;)
+ (NSString * _Nonnull)VIDEO_FINISHED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_MUTE;)
+ (NSString * _Nonnull)VIDEO_MUTE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_UNMUTE;)
+ (NSString * _Nonnull)VIDEO_UNMUTE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_SESSION_INITIALIZED;)
+ (NSString * _Nonnull)AD_SESSION_INITIALIZED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_SESSION_LOADED;)
+ (NSString * _Nonnull)AD_SESSION_LOADED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_SESSION_STARTED;)
+ (NSString * _Nonnull)AD_SESSION_STARTED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_SESSION_STOPPED;)
+ (NSString * _Nonnull)AD_SESSION_STOPPED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_FIRST_QUARTILE;)
+ (NSString * _Nonnull)VIDEO_AD_FIRST_QUARTILE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_MIDPOINT;)
+ (NSString * _Nonnull)VIDEO_AD_MIDPOINT SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_THIRD_QUARTILE;)
+ (NSString * _Nonnull)VIDEO_AD_THIRD_QUARTILE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_COMPLETE;)
+ (NSString * _Nonnull)VIDEO_AD_COMPLETE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_PAUSE;)
+ (NSString * _Nonnull)VIDEO_AD_PAUSE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_RESUME;)
+ (NSString * _Nonnull)VIDEO_AD_RESUME SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_BUFFER_START;)
+ (NSString * _Nonnull)VIDEO_AD_BUFFER_START SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_BUFFER_FINISH;)
+ (NSString * _Nonnull)VIDEO_AD_BUFFER_FINISH SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_VOLUME_CHANGE;)
+ (NSString * _Nonnull)VIDEO_AD_VOLUME_CHANGE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_SKIPPED;)
+ (NSString * _Nonnull)VIDEO_AD_SKIPPED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull VIDEO_AD_CLICKED;)
+ (NSString * _Nonnull)VIDEO_AD_CLICKED SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull LOAD;)
+ (NSString * _Nonnull)LOAD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull LOAD_FAIL;)
+ (NSString * _Nonnull)LOAD_FAIL SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull CACHE;)
+ (NSString * _Nonnull)CACHE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull RESPONSE;)
+ (NSString * _Nonnull)RESPONSE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull RENDER;)
+ (NSString * _Nonnull)RENDER SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull RENDER_ERROR;)
+ (NSString * _Nonnull)RENDER_ERROR SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull COMPANION_VIEW;)
+ (NSString * _Nonnull)COMPANION_VIEW SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull REWARD;)
+ (NSString * _Nonnull)REWARD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull SESSION_REPORT_INFO;)
+ (NSString * _Nonnull)SESSION_REPORT_INFO SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNumber;

SWIFT_CLASS("_TtC5HyBid18HyBidConsentConfig")
@interface HyBidConsentConfig : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidConsentConfig * _Nonnull sharedConfig;)
+ (HyBidConsentConfig * _Nonnull)sharedConfig SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@property (nonatomic) BOOL coppa;
@end


SWIFT_CLASS("_TtC5HyBid14HyBidConstants")
@interface HyBidConstants : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull HYBID_SDK_NAME;)
+ (NSString * _Nonnull)HYBID_SDK_NAME SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull HYBID_SDK_VERSION;)
+ (NSString * _Nonnull)HYBID_SDK_VERSION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull HYBID_OMSDK_VERSION;)
+ (NSString * _Nonnull)HYBID_OMSDK_VERSION SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull HYBID_OMSDK_IDENTIFIER;)
+ (NSString * _Nonnull)HYBID_OMSDK_IDENTIFIER SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class HyBidAd;
@protocol HyBidInterstitialAdDelegate;
@class UIViewController;

SWIFT_CLASS("_TtC5HyBid19HyBidInterstitialAd")
@interface HyBidInterstitialAd : NSObject
@property (nonatomic, strong) HyBidAd * _Nullable ad;
@property (nonatomic) BOOL isReady;
@property (nonatomic) BOOL isMediation;
@property (nonatomic) BOOL isAutoCacheOnLoad;
- (nonnull instancetype)initWithDelegate:(id <HyBidInterstitialAdDelegate> _Nonnull)delegate;
- (nonnull instancetype)initWithZoneID:(NSString * _Nullable)zoneID andWithDelegate:(id <HyBidInterstitialAdDelegate> _Nonnull)delegate;
- (nonnull instancetype)initWithZoneID:(NSString * _Nullable)zoneID withAppToken:(NSString * _Nullable)appToken andWithDelegate:(id <HyBidInterstitialAdDelegate> _Nonnull)delegate;
- (void)load;
- (void)loadExchangeAd;
- (void)setSkipOffset:(NSInteger)seconds;
- (void)setVideoSkipOffset:(NSInteger)seconds;
- (void)setHTMLSkipOffset:(NSInteger)seconds;
- (void)setCloseOnFinish:(BOOL)closeOnFinish;
- (void)prepare;
- (void)setMediationVendor:(NSString * _Nonnull)mediationVendor;
- (void)prepareAdWithContent:(NSString * _Nonnull)adContent;
- (void)prepareAdWithAdReponse:(NSString * _Nonnull)adReponse;
- (void)prepareVideoTagFrom:(NSString * _Nonnull)url;
- (void)prepareCustomMarkupFrom:(NSString * _Nonnull)markup;
- (void)show;
- (void)showFromViewController:(UIViewController * _Nonnull)viewController;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end





SWIFT_PROTOCOL("_TtP5HyBid27HyBidInterstitialAdDelegate_")
@protocol HyBidInterstitialAdDelegate
- (void)interstitialDidLoad;
- (void)interstitialDidFailWithError:(NSError * _Null_unspecified)error;
- (void)interstitialDidTrackImpression;
- (void)interstitialDidTrackClick;
- (void)interstitialDidDismiss;
@end


SWIFT_CLASS("_TtC5HyBid19HyBidLocationConfig")
@interface HyBidLocationConfig : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidLocationConfig * _Nonnull sharedConfig;)
+ (HyBidLocationConfig * _Nonnull)sharedConfig SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@property (nonatomic) BOOL locationTrackingEnabled;
@property (nonatomic) BOOL locationUpdatesEnabled;
@end


SWIFT_CLASS("_TtC5HyBid11HyBidLogger")
@interface HyBidLogger : NSObject
+ (void)setLogLevel:(HyBidLogLevel)logLevel;
+ (void)errorLogFromClass:(NSString * _Nonnull)className fromMethod:(NSString * _Nonnull)fromMethod withMessage:(NSString * _Nonnull)withMessage;
+ (void)warningLogFromClass:(NSString * _Nonnull)className fromMethod:(NSString * _Nonnull)fromMethod withMessage:(NSString * _Nonnull)withMessage;
+ (void)infoLogFromClass:(NSString * _Nonnull)className fromMethod:(NSString * _Nonnull)fromMethod withMessage:(NSString * _Nonnull)withMessage;
+ (void)debugLogFromClass:(NSString * _Nonnull)className fromMethod:(NSString * _Nonnull)fromMethod withMessage:(NSString * _Nonnull)withMessage;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSDictionary;
@class NSCoder;

SWIFT_CLASS("_TtC5HyBid23HyBidMRAIDCloseCardView")
@interface HyBidMRAIDCloseCardView : UIView
- (nonnull instancetype)initWithDictionary:(NSDictionary * _Nonnull)dictionary OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder SWIFT_UNAVAILABLE;
- (void)didMoveToSuperview;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end


@interface HyBidMRAIDCloseCardView (SWIFT_EXTENSION(HyBid)) <HyBidContentInfoViewDelegate>
- (void)contentInfoViewWidthNeedsUpdate:(NSNumber * _Null_unspecified)width;
@end

@class HyBidSkipOffset;

SWIFT_CLASS("_TtC5HyBid20HyBidRenderingConfig")
@interface HyBidRenderingConfig : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidRenderingConfig * _Nonnull sharedConfig;)
+ (HyBidRenderingConfig * _Nonnull)sharedConfig SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull videoSkipOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull interstitialHtmlSkipOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull rewardedHtmlSkipOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull rewardedVideoSkipOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull endCardCloseOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, strong) HyBidSkipOffset * _Nonnull nativeCloseButtonOffset SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL showEndCard SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) HyBidInterstitialActionBehaviour interstitialActionBehaviour SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL interstitialCloseOnFinish SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL rewardedCloseOnFinish SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) HyBidAudioStatus audioStatus SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL mraidExpand SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL interstitialSKOverlay SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic) BOOL rewardedSKOverlay SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@property (nonatomic, readonly) BOOL bannerSKOverlay SWIFT_DEPRECATED_MSG("Please note this method will no longer be supported from HyBid SDK v3.0. While we do not recommend changes to this setting, you can reach out to your account managers for customisations.");
@end

@class HyBidReportingEvent;

SWIFT_PROTOCOL("_TtP5HyBid22HyBidReportingDelegate_")
@protocol HyBidReportingDelegate
- (void)onEventWith:(HyBidReportingEvent * _Nonnull)event;
@end


SWIFT_CLASS("_TtC5HyBid19HyBidReportingEvent")
@interface HyBidReportingEvent : NSObject
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nonnull properties;
@property (nonatomic, copy) NSString * _Nonnull eventType;
- (nonnull instancetype)initWith:(NSString * _Nonnull)eventType adFormat:(NSString * _Nullable)adFormat properties:(NSDictionary<NSString *, id> * _Nullable)properties OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWith:(NSString * _Nonnull)eventType errorMessage:(NSString * _Nullable)errorMessage properties:(NSDictionary<NSString *, id> * _Nullable)properties OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)toJSON SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC5HyBid21HyBidReportingManager")
@interface HyBidReportingManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidReportingManager * _Nonnull sharedInstance;)
+ (HyBidReportingManager * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, copy) NSArray<HyBidReportingEvent *> * _Nonnull events;
@property (nonatomic, weak) id <HyBidReportingDelegate> _Nullable delegate;
- (void)reportEventFor:(HyBidReportingEvent * _Nonnull)event;
- (void)reportEventsFor:(NSArray<HyBidReportingEvent *> * _Nonnull)events;
- (void)clearEvents;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@protocol HyBidRewardedAdDelegate;

SWIFT_CLASS("_TtC5HyBid15HyBidRewardedAd")
@interface HyBidRewardedAd : NSObject
@property (nonatomic, strong) HyBidAd * _Nullable ad;
@property (nonatomic) BOOL isReady;
@property (nonatomic) BOOL isMediation;
@property (nonatomic) BOOL isAutoCacheOnLoad;
- (nonnull instancetype)initWithDelegate:(id <HyBidRewardedAdDelegate> _Nonnull)delegate;
- (nonnull instancetype)initWithZoneID:(NSString * _Nullable)zoneID andWithDelegate:(id <HyBidRewardedAdDelegate> _Nonnull)delegate;
- (nonnull instancetype)initWithZoneID:(NSString * _Nullable)zoneID withAppToken:(NSString * _Nullable)appToken andWithDelegate:(id <HyBidRewardedAdDelegate> _Nonnull)delegate;
- (void)load;
- (void)loadExchangeAd;
- (void)setSkipOffset:(NSInteger)seconds;
- (void)setHTMLSkipOffset:(NSInteger)seconds;
- (void)setCloseOnFinish:(BOOL)closeOnFinish;
- (void)prepare;
- (void)setMediationVendor:(NSString * _Nonnull)mediationVendor;
- (void)prepareCustomMarkupFrom:(NSString * _Nonnull)markup;
- (void)prepareAdWithContent:(NSString * _Nonnull)adContent;
- (void)prepareAdWithAdReponse:(NSString * _Nonnull)adReponse;
- (void)show;
- (void)showFromViewController:(UIViewController * _Nonnull)viewController;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end





SWIFT_PROTOCOL("_TtP5HyBid23HyBidRewardedAdDelegate_")
@protocol HyBidRewardedAdDelegate
- (void)rewardedDidLoad;
- (void)rewardedDidFailWithError:(NSError * _Null_unspecified)error;
- (void)rewardedDidTrackImpression;
- (void)rewardedDidTrackClick;
- (void)rewardedDidDismiss;
- (void)onReward;
@end

@class HyBidTargetingModel;

SWIFT_CLASS("_TtC5HyBid14HyBidSDKConfig")
@interface HyBidSDKConfig : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidSDKConfig * _Nonnull sharedConfig;)
+ (HyBidSDKConfig * _Nonnull)sharedConfig SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@property (nonatomic) BOOL test;
@property (nonatomic, strong) HyBidTargetingModel * _Nullable targeting;
@property (nonatomic, copy) NSString * _Nullable appToken;
@property (nonatomic, copy) NSString * _Nonnull apiURL;
@property (nonatomic, copy) NSString * _Nonnull openRtbApiURL;
@property (nonatomic, copy) NSString * _Nullable appID;
@end


SWIFT_CLASS("_TtC5HyBid19HyBidSessionManager")
@interface HyBidSessionManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidSessionManager * _Nonnull sharedInstance;)
+ (HyBidSessionManager * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, copy) NSDictionary<NSString *, NSNumber *> * _Nonnull impressionCounter;
@property (nonatomic, copy) NSString * _Nonnull sessionDuration;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (void)setStartSession;
- (void)updateSessionWithZoneID:(NSString * _Nonnull)zoneID;
- (void)incrementImpressionCounterWithZoneID:(NSString * _Nonnull)zoneID;
- (void)sessionDurationWithZoneID:(NSString * _Nonnull)zoneID;
- (void)setAgeOfAppSinceCreated;
- (NSString * _Nonnull)getAgeOfApp SWIFT_WARN_UNUSED_RESULT;
@end

@class CLLocation;

SWIFT_CLASS("_TtC5HyBid13HyBidSettings")
@interface HyBidSettings : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidSettings * _Nonnull sharedInstance;)
+ (HyBidSettings * _Nonnull)sharedInstance SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic) BOOL supportMultipleFidelities;
@property (nonatomic, readonly, copy) NSString * _Nullable advertisingId;
@property (nonatomic, readonly, copy) NSString * _Nonnull os;
@property (nonatomic, readonly, copy) NSString * _Nonnull osVersion;
@property (nonatomic, readonly, copy) NSString * _Nonnull deviceName;
@property (nonatomic, readonly, copy) NSString * _Nonnull deviceWidth;
@property (nonatomic, readonly, copy) NSString * _Nonnull deviceHeight;
@property (nonatomic, readonly, copy) NSString * _Nonnull orientation;
@property (nonatomic, readonly, copy) NSString * _Nonnull deviceSound;
@property (nonatomic, readonly, strong) NSNumber * _Nonnull audioVolumePercentage;
@property (nonatomic, readonly, copy) NSString * _Nullable locale;
@property (nonatomic, copy) NSString * _Nullable sdkVersion;
@property (nonatomic, readonly, copy) NSString * _Nullable appBundleID;
@property (nonatomic, readonly, copy) NSString * _Nullable appVersion;
@property (nonatomic, readonly, strong) CLLocation * _Nullable location;
@property (nonatomic, readonly, copy) NSString * _Nullable identifierForVendor;
@property (nonatomic, readonly, copy) NSString * _Nullable ip;
@property (nonatomic, readonly, strong) NSNumber * _Nullable appTrackingTransparency;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC5HyBid15HyBidSkipOffset")
@interface HyBidSkipOffset : NSObject
@property (nonatomic, strong) NSNumber * _Nullable offset;
@property (nonatomic) BOOL isCustom;
@property (nonatomic, strong) NSNumber * _Nonnull style;
- (nonnull instancetype)initWithOffset:(NSNumber * _Nullable)offset isCustom:(BOOL)isCustom OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithOffset:(NSNumber * _Nullable)offset isCustom:(BOOL)isCustom style:(NSNumber * _Nonnull)style OBJC_DESIGNATED_INITIALIZER;
- (void)configureWithOffset:(NSNumber * _Nullable)offset isCustom:(BOOL)isCustom style:(NSNumber * _Nonnull)style;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC5HyBid19HyBidTargetingModel")
@interface HyBidTargetingModel : NSObject
@property (nonatomic, strong) NSNumber * _Nullable age;
@property (nonatomic, copy) NSArray<NSString *> * _Nonnull interests;
@property (nonatomic, copy) NSString * _Nullable gender;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC5HyBid21HyBidViewbilityConfig")
@interface HyBidViewbilityConfig : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) HyBidViewbilityConfig * _Nonnull sharedConfig;)
+ (HyBidViewbilityConfig * _Nonnull)sharedConfig SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@property (nonatomic) HyBidImpressionTrackerMethod impressionTrackerMethod;
@property (nonatomic) NSInteger minVisibleTime;
@property (nonatomic) double minVisiblePercent;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
