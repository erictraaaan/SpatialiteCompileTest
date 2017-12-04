//
//  ShapeKitGeometry+Predicates.h
//  ShapeKit

// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import <Foundation/Foundation.h>
#import "ShapeKitGeometry.h"

@interface ShapeKitGeometry (Predicates)

/** @name Spatial predicates methods 
 * All of the following spatial predicate methods take another GEOSGeometry instance (other) as a parameter, and return a boolean.
 */

/** Returns TRUE if the DE-9IM intersection matrix for the two geometries is "FF*FF****".
 */
-(BOOL)isDisjointFromGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the DE-9IM intersection matrix for the two geometries is "FT*******", "F**T*****" or "F***T****".
 */
-(BOOL)touchesGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if isDisjointFromGeometry is FALSE.
 */
-(BOOL)intersectsGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the DE-9IM intersection matrix for the two Geometries is "T*T******" (for a point and a curve,a point and an area or a line and an area) 0******** (for two curves).
 */
-(BOOL)crossesGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the DE-9IM intersection matrix for the two geometries is "T*F**F***".
*/
-(BOOL)isWithinGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if isWithinGeometry is FALSE.
 */
-(BOOL)containsGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the DE-9IM intersection matrix for the two geometries is "T*T***T**" (for two points or two surfaces) "1*T***T**" (for two curves).
 */
-(BOOL)overlapsGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the DE-9IM intersection matrix for the two geometries is "T*F**FFF*".
 */
-(BOOL)isEqualToGeometry:(ShapeKitGeometry *)compareGeometry;

/** Returns TRUE if the elements in the DE-9IM intersection matrix for this geometry and the other matches the given pattern – a string of nine characters from the alphabet: {T, F, *, 0}.
 */
-(BOOL)isRelatedToGeometry:(ShapeKitGeometry *)compareGeometry withRelatePattern:(NSString *)pattern;

@end
