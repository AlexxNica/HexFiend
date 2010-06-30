//
//  HFByteRangeAttributeArray.h
//  HexFiend_2
//
//  Created by Peter Ammon on 8/24/09.
//  Copyright 2009 ridiculous_fish. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HFByteRangeAttributeArray : NSObject <NSMutableCopying> {
    NSMutableArray *attributeRuns;
}

/*! Returns the set of attributes at the given index, and the length over which those attributes are valid (if not NULL). */
- (NSSet *)attributesAtIndex:(unsigned long long)index length:(unsigned long long *)length;

/*! Returns the first range of a given attribute.  If it is not present, returns {ULLONG_MAX, ULLONG_MAX} */
- (HFRange)rangeOfAttribute:(NSString *)attribute;

/*! Adds a given attribute for a given range. */
- (void)addAttribute:(NSString *)attributeName range:(HFRange)range;

/*! Removes the given attribute within the given range. */
- (void)removeAttribute:(NSString *)attributeName range:(HFRange)range;

/*! Removes the given attribute entirely. */
- (void)removeAttribute:(NSString *)attributeName;

/*! Returns whether the receiver is empty. */
- (BOOL)isEmpty;

/*! Transfer attributes in the given range from array, adding baseOffset to each attribute range. range is interpreted as a range in array. */
- (void)transferAttributesFromAttributeArray:(HFByteRangeAttributeArray *)array range:(HFRange)range baseOffset:(unsigned long long)baseOffset;

@end
