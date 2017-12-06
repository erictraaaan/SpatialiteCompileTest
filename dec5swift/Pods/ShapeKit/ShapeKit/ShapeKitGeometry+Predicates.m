//
//  ShapeKitGeometry+Predicates.m
//  ShapeKit

// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import "ShapeKitGeometry+Predicates.h"
#import "ShapeKitPrivateInterface.h"

@implementation ShapeKitGeometry (predicates)

-(BOOL)isDisjointFromGeometry:(ShapeKitGeometry *)compareGeometry {
    
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;
    
    BOOL disjoint = GEOSDisjoint_r(handle, geosGeom, compareGeometry.geosGeom);
    return disjoint;
}

-(BOOL)touchesGeometry:(ShapeKitGeometry *)compareGeometry {
    
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL touches = GEOSTouches_r(handle, geosGeom, compareGeometry.geosGeom);
    return touches;
}

-(BOOL)intersectsGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL intersects = GEOSIntersects_r(handle, geosGeom, compareGeometry.geosGeom);
    return intersects;
}

-(BOOL)crossesGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL crosses = GEOSCrosses_r(handle, geosGeom, compareGeometry.geosGeom);
    return crosses;
}

-(BOOL)isWithinGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL within = GEOSWithin_r(handle, geosGeom, compareGeometry.geosGeom);
    return within;
}

-(BOOL)containsGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL contains = GEOSContains_r(handle, geosGeom, compareGeometry.geosGeom);
    return contains;
}

-(BOOL)overlapsGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL overlaps = GEOSOverlaps_r(handle, geosGeom, compareGeometry.geosGeom);
    return overlaps;
}

-(BOOL)isEqualToGeometry:(ShapeKitGeometry *)compareGeometry {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL equals = GEOSEquals_r(handle, geosGeom, compareGeometry.geosGeom);
    return equals;
}


-(BOOL)isRelatedToGeometry:(ShapeKitGeometry *)compareGeometry withRelatePattern:(NSString *)pattern {
    GEOSContextHandle_t handle = self.handle;
    GEOSGeometry *geosGeom = self.geosGeom;

    BOOL patt_success = GEOSRelatePattern_r(handle, geosGeom, compareGeometry.geosGeom, [pattern UTF8String]);
    return patt_success;
}

@end
