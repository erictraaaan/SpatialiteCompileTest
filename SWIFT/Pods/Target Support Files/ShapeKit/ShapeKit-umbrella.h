#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ShapeKit.h"
#import "ShapeKitFactory.h"
#import "ShapeKitGeometry+Predicates.h"
#import "ShapeKitGeometry+Topology.h"
#import "ShapeKitGeometry.h"
#import "ShapeKitPolyline+Linearref.h"
#import "ShapeKitPrivateInterface.h"

FOUNDATION_EXPORT double ShapeKitVersionNumber;
FOUNDATION_EXPORT const unsigned char ShapeKitVersionString[];

