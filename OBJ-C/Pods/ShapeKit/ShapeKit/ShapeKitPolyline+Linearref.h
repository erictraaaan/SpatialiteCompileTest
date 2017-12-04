//
//  ShapeKitPolyline+Linearref.h
//  ShapeKit
//
//  Created by Andrea Cremaschi on 31/07/12.
// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import "ShapeKitGeometry.h"

/// @name Linear referencing along a linear Geometry
@interface ShapeKitPolyline (Linearref)

/// @name Projections

/** Returns the distance (float) from the origin of the geometry (LineString or MultiLineString) to the point projected on the geometry (that is to a point of the line the closest to the given point).*/
- (double) distanceFromOriginToProjectionOfPoint: (ShapeKitPoint *)point;

/** Returns the  distance as a float between 0 (origin) and 1 (endpoint) from the origin of the geometry (LineString or MultiLineString) to the point projected on the geometry (that is to a point of the line the closest to the given point).*/
- (double) normalizedDistanceFromOriginToProjectionOfPoint: (ShapeKitPoint *)point;

/** Returns the middle point of a ShapeKitPolyline */
- (ShapeKitPoint *) middlePoint;

/// @name Interpolations

/** Given a distance (double), returns the point (or closest point) within the geometry (LineString or MultiLineString) at that distance. */
- (ShapeKitPoint *) interpolatePointAtDistance: (double) distance;

/** Given a distance as a float between 0 (origin) and 1 (endpoint), returns the point (or closest point) within the geometry (LineString or MultiLineString) at that distance. */
- (ShapeKitPoint *) interpolatePointAtNormalizedDistance: (double) fraction;



@end
