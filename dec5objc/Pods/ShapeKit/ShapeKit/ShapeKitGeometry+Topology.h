//
//  ShapeKitGeometry+Topology.h
//  ShapeKit
//
//  Created by Michael Weisman on 10-08-26.
// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import <Foundation/Foundation.h>
#import "ShapeKitGeometry.h"


@interface ShapeKitGeometry (Topology)

/** @name Topological properties */

/** Returns a ShapeKitPolygon that represents all points whose distance from this geometry is less than or equal to the given width.
 */
-(ShapeKitPolygon *)bufferWithWidth:(double)width;

/** Returns the boundary as a newly allocated Geometry object. */
-(ShapeKitGeometry *)boundary;

/** Returns a ShapeKitPoint representing the geometric center of the geometry. The point is not guaranteed to be on the interior of the geometry. */
-(ShapeKitPoint *)centroid;

/** Returns the smallest ShapeKitPolygon that contains all the points in the geometry.
 */
-(ShapeKitPolygon *)convexHull;

/** Returns a ShapeKitPolygon that represents the bounding envelope of this geometry.
 */
-(ShapeKitPolygon *)envelope;

/** Returns a ShapeKitPolygon that represents the bounding envelope of this geometry. */
-(ShapeKitPoint *)pointOnSurface;

/** Returns the DE-9IM intersection matrix (a string) representing the topological relationship between this geometry and the other. */
-(NSString *)relationshipWithGeometry:(ShapeKitGeometry *)geometry;

/** Returns a ShapeKitGeometry representing the points shared by this geometry and other. */
-(ShapeKitGeometry *)intersectionWithGeometry:(ShapeKitGeometry *)geometry;

/** Returns a ShapeKitGeometry representing the points making up this geometry that do not make up other. */
-(ShapeKitGeometry *)differenceWithGeometry:(ShapeKitGeometry *)geometry;

/** Returns a ShapeKitGeometry representing all the points in this geometry and the other. */
-(ShapeKitGeometry *)unionWithGeometry:(ShapeKitGeometry *)geometry;

@end

@interface ShapeKitMultiPolygon (Topology)

/** Returns a ShapeKitPolygon that is the union of all of the component polygons in this collection.
 * The algorithm employed is significantly more efficient (faster) than trying to union the geometries together individually. */
-(ShapeKitGeometry *)cascadedUnion;

@end