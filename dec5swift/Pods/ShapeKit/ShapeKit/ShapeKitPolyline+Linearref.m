//
//  ShapeKitPolyline+Linearref.m
//  ShapeKit
//
//  Created by Andrea Cremaschi on 31/07/12.
//
// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.


#import "ShapeKitPolyline+Linearref.h"
#import "ShapeKitPrivateInterface.h"

@implementation ShapeKitPolyline (Linearref)

// Return distance of point projected on line
- (double) distanceFromOriginToProjectionOfPoint: (ShapeKitPoint *)point
{
    return GEOSProject_r(self.handle, self.geosGeom, point.geosGeom);
}

- (double) normalizedDistanceFromOriginToProjectionOfPoint: (ShapeKitPoint *)point
{
    return GEOSProjectNormalized_r(self.handle, self.geosGeom, point.geosGeom);
}

// Return closest point to given distance within geometry 
- (ShapeKitPoint *) interpolatePointAtDistance: (double) distance
{
    return [[ShapeKitPoint alloc] initWithGeosGeometry: GEOSInterpolate_r(self.handle, self.geosGeom, distance)];
}

- (ShapeKitPoint *) interpolatePointAtNormalizedDistance: (double) fraction
{
    return [[ShapeKitPoint alloc] initWithGeosGeometry: GEOSInterpolateNormalized_r(self.handle, self.geosGeom, fraction)];
}

- (ShapeKitPoint *) middlePoint
{
    return [self interpolatePointAtNormalizedDistance: 0.5];
}

@end
