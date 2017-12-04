//
//  ShapeKitPrivateInterface.h
//  ShapeKit
//
//  Created by Andrea Cremaschi on 30/11/12.
//
//

#ifndef ShapeKit_ShapeKitPrivateInterface_h
#define ShapeKit_ShapeKitPrivateInterface_h

#import <geos_c.h>

@interface ShapeKitGeometry (PrivateInterface)

@property (readwrite, copy) NSString *wktGeom;
@property (readwrite, copy) NSString *geomType;

@property (readwrite, copy) NSString *projDefinition;

@property (readwrite) GEOSGeometry *geosGeom;
@property (readwrite) GEOSContextHandle_t handle;

@property (readwrite) CLLocationCoordinate2D *coords;

@end

#endif
