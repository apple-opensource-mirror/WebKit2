/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <WebKit/WKFoundation.h>

#if WK_API_ENABLED

#import <Foundation/Foundation.h>

@class WKDOMNode, WKDOMDocument;

typedef NS_ENUM(NSInteger, WKDOMRangeDirection) {
    WKDOMRangeDirectionForward,
    WKDOMRangeDirectionBackword
};


WK_CLASS_AVAILABLE(macosx(10.10), ios(8.0))
@interface WKDOMRange : NSObject

- (id)initWithDocument:(WKDOMDocument *)document;

- (void)setStart:(WKDOMNode *)node offset:(int)offset;
- (void)setEnd:(WKDOMNode *)node offset:(int)offset;
- (void)collapse:(BOOL)toStart;
- (void)selectNode:(WKDOMNode *)node;
- (void)selectNodeContents:(WKDOMNode *)node;

- (WKDOMRange *)rangeByExpandingToWordBoundaryByCharacters:(NSUInteger)characters inDirection:(WKDOMRangeDirection)direction;

@property(readonly, retain) WKDOMNode *startContainer;
@property(readonly) NSInteger startOffset;
@property(readonly, retain) WKDOMNode *endContainer;
@property(readonly) NSInteger endOffset;
@property(readonly, copy) NSString *text;
@property(readonly) BOOL isCollapsed;
@property(readonly) NSArray *textRects;

@end

#endif // WK_API_ENABLED
