/*
 * Copyright (C) 2016, 2018 Apple Inc. All rights reserved.
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
#import <WebKit/WKBase.h>

NS_ASSUME_NONNULL_BEGIN

@class WKWebView;
@class _WKAutomationSession;

typedef NS_ENUM(NSInteger, _WKAutomationSessionJavaScriptDialogType) {
    _WKAutomationSessionJavaScriptDialogTypeNone = 1,
    _WKAutomationSessionJavaScriptDialogTypeAlert,
    _WKAutomationSessionJavaScriptDialogTypeConfirm,
    _WKAutomationSessionJavaScriptDialogTypePrompt,
} WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));

typedef NS_ENUM(NSUInteger, _WKAutomationSessionBrowsingContextOptions) {
    _WKAutomationSessionBrowsingContextOptionsPreferNewTab = 1 << 0,
} WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));

@protocol _WKAutomationSessionDelegate <NSObject>
@optional

- (void)_automationSessionDidDisconnectFromRemote:(_WKAutomationSession *)automationSession;

- (void)_automationSession:(_WKAutomationSession *)automationSession requestNewWebViewWithOptions:(_WKAutomationSessionBrowsingContextOptions)options completionHandler:(void(^)(WKWebView * _Nullable))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestHideWindowOfWebView:(WKWebView *)webView completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestRestoreWindowOfWebView:(WKWebView *)webView completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestMaximizeWindowOfWebView:(WKWebView *)webView completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestSwitchToWebView:(WKWebView *)webView completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (BOOL)_automationSession:(_WKAutomationSession *)automationSession isShowingJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession dismissCurrentJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession acceptCurrentJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (nullable NSString *)_automationSession:(_WKAutomationSession *)automationSession messageOfCurrentJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession setUserInput:(NSString *)value forCurrentJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (_WKAutomationSessionJavaScriptDialogType)_automationSession:(_WKAutomationSession *)automationSession typeOfCurrentJavaScriptDialogForWebView:(WKWebView *)webView WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));

// FIXME 37408718: Objective-C delegate methods shouldn't use C API types like WKPageRef. We need to
// migrate clients to use WKWebView, or expose the same behavior via a C SPI for those clients.
- (void)_automationSession:(_WKAutomationSession *)automationSession requestNewPageWithOptions:(_WKAutomationSessionBrowsingContextOptions)options completionHandler:(void(^)(WKPageRef))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestHideWindowOfPage:(WKPageRef)page completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestRestoreWindowOfPage:(WKPageRef)page completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestMaximizeWindowOfPage:(WKPageRef)page completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (void)_automationSession:(_WKAutomationSession *)automationSession requestSwitchToPage:(WKPageRef)page completionHandler:(void(^)(void))completionHandler WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
- (BOOL)_automationSession:(_WKAutomationSession *)automationSession isShowingJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession dismissCurrentJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession acceptCurrentJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (nullable NSString *)_automationSession:(_WKAutomationSession *)automationSession messageOfCurrentJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (void)_automationSession:(_WKAutomationSession *)automationSession setUserInput:(NSString *)value forCurrentJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(10.13), ios(11.0));
- (_WKAutomationSessionJavaScriptDialogType)_automationSession:(_WKAutomationSession *)automationSession typeOfCurrentJavaScriptDialogOnPage:(WKPageRef)page WK_API_AVAILABLE(macosx(WK_MAC_TBA), ios(WK_IOS_TBA));
@end

NS_ASSUME_NONNULL_END

#endif // WK_API_ENABLED
