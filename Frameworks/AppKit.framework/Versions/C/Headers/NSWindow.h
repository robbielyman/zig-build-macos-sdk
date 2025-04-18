/*
    NSWindow.h
    Application Kit
    Copyright (c) 1994-2024, Apple Inc.
    All rights reserved.
*/

#import <Foundation/NSArray.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSGeometry.h>

#import <AppKit/AppKitDefines.h>
#import <AppKit/NSAnimation.h>
#import <AppKit/NSAppearance.h>
#import <AppKit/NSApplication.h>
#import <AppKit/NSGraphics.h>
#import <AppKit/NSPasteboard.h>
#import <AppKit/NSPreviewRepresentingActivityItem.h>
#import <AppKit/NSResponder.h>
#import <AppKit/NSUserInterfaceItemIdentification.h>
#import <AppKit/NSUserInterfaceValidation.h>
#import <AppKit/NSMenu.h>

#import <ApplicationServices/ApplicationServices.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)
APPKIT_API_UNAVAILABLE_BEGIN_MACCATALYST

@class CADisplayLink, NSButton, NSButtonCell, NSColor, NSImage, NSScreen, NSNotification, NSText, NSView, NSMutableSet, NSSet, NSDate, NSToolbar, NSGraphicsContext, NSURL, NSColorSpace, NSDockTile, NSViewController, NSTitlebarAccessoryViewController, NSEvent, NSWindowController, NSWindowTab, NSWindowTabGroup;
    
@protocol NSWindowDelegate;

static const NSAppKitVersion NSAppKitVersionNumberWithCustomSheetPosition = 686.0;
static const NSAppKitVersion NSAppKitVersionNumberWithDeferredWindowDisplaySupport = 1019.0;

/*!
 * @typedef NSWindowStyleMask
 *
 * @const NSWindowStyleMaskBorderless
 * @const NSWindowStyleMaskTitled
 * @const NSWindowStyleMaskClosable
 * @const NSWindowStyleMaskMiniaturizable
 * @const NSWindowStyleMaskResizable
 * @const NSWindowStyleMaskTexturedBackground  Textured window style is deprecated and should no longer be used. Specifies a window with textured background. Textured windows generally don't draw a top border line under the titlebar/toolbar. To get that line, use the \c NSUnifiedTitleAndToolbarWindowMask mask.
 * @const NSWindowStyleMaskUnifiedTitleAndToolbar  Specifies a window whose titlebar and toolbar have a unified look - that is, a continuous background. Under the titlebar and toolbar a horizontal separator line will appear.
 * @const NSWindowStyleMaskFullScreen  When present, the window will appear full screen. This mask is automatically toggled when \c -toggleFullScreen: is called.
 * @const NSWindowStyleMaskFullSizeContentView If set, the \c contentView will consume the full size of the window; it can be combined with other window style masks, but is only respected for windows with a titlebar. Utilizing this mask opts-in to layer-backing. Utilize the \c contentLayoutRect or auto-layout \c contentLayoutGuide to layout views underneath the titlebar/toolbar area.
 * @const NSWindowStyleMaskUtilityWindow Only applicable for \c NSPanel (or a subclass thereof).
 * @const NSWindowStyleMaskDocModalWindow Only applicable for \c NSPanel (or a subclass thereof).
 * @const NSWindowStyleMaskNonactivatingPanel  Specifies that a panel that does not activate the owning application. Only applicable for \c NSPanel (or a subclass thereof).
 * @const NSWindowStyleMaskHUDWindow Specifies a heads up display panel.  Only applicable for \c NSPanel (or a subclass thereof).
 */
typedef NS_OPTIONS(NSUInteger, NSWindowStyleMask) {
    NSWindowStyleMaskBorderless = 0,
    NSWindowStyleMaskTitled = 1 << 0,
    NSWindowStyleMaskClosable = 1 << 1,
    NSWindowStyleMaskMiniaturizable = 1 << 2,
    NSWindowStyleMaskResizable	= 1 << 3,
    NSWindowStyleMaskTexturedBackground API_DEPRECATED("Textured window style should no longer be used", macos(10.2, 11.0)) = 1 << 8,
    NSWindowStyleMaskUnifiedTitleAndToolbar = 1 << 12,
    NSWindowStyleMaskFullScreen API_AVAILABLE(macos(10.7)) = 1 << 14,
    NSWindowStyleMaskFullSizeContentView API_AVAILABLE(macos(10.10)) = 1 << 15,
    NSWindowStyleMaskUtilityWindow = 1 << 4,
    NSWindowStyleMaskDocModalWindow = 1 << 6,
    NSWindowStyleMaskNonactivatingPanel = 1 << 7,
    NSWindowStyleMaskHUDWindow API_AVAILABLE(macos(10.6)) = 1 << 13
};

// Additional NSModalResponse values
static const NSModalResponse NSModalResponseOK = 1;
static const NSModalResponse NSModalResponseCancel = 0;

/// Used with \c NSRunLoop's `-performSelector:target:argument:order:modes:`.
enum {
    NSDisplayWindowRunLoopOrdering	= 600000,
    NSResetCursorRectsRunLoopOrdering	= 700000
};

/*!
 * @typedef NSWindowSharingType
 *
 * @const NSWindowSharingNone          Window contents may not be read by another process.
 * @const NSWindowSharingReadOnly   Window contents may be read by another process.
 */
typedef NS_ENUM(NSUInteger, NSWindowSharingType) {
    NSWindowSharingNone = 0,
    NSWindowSharingReadOnly = 1,
} API_AVAILABLE(macos(10.5));

/*!
 * @typedef NSWindowCollectionBehavior
 *
 * @const NSWindowCollectionBehaviorPrimary Marks a window as primary. This collection behavior should commonly be used for document or viewer windows.
 * @const NSWindowCollectionBehaviorAuxiliary Marks a window as auxiliary. This collection behavior should commonly be used for About or Settings windows, as well as utility panes.
 * @const NSWindowCollectionBehaviorCanJoinAllApplications Marks a window as able to join all applications, allowing it to join other apps' sets and full screen spaces when eligible. This collection behavior should commonly be used for floating windows and system overlays.
 *
 * @discussion You may specify at most one of @c NSWindowCollectionBehaviorPrimary, @c NSWindowCollectionBehaviorAuxiliary, or @c NSWindowCollectionBehaviorCanJoinAllApplications. If unspecified, the window gets the default treatment determined by its other collection behaviors.
 *
 * @const NSWindowCollectionBehaviorDefault
 * @const NSWindowCollectionBehaviorCanJoinAllSpaces
 * @const NSWindowCollectionBehaviorMoveToActiveSpace
 *
 * @discussion You may specify at most one of \c NSWindowCollectionBehaviorManaged, \c NSWindowCollectionBehaviorTransient, or \c NSWindowCollectionBehaviorStationary.  If neither is specified, the window gets the default behavior determined by its window level.
 *
 * @const NSWindowCollectionBehaviorManaged Participates in spaces, exposé.  Default behavior if `windowLevel == NSNormalWindowLevel`.
 * @const NSWindowCollectionBehaviorTransient Floats in spaces, hidden by exposé.  Default behavior if `windowLevel != NSNormalWindowLevel`.
 * @const NSWindowCollectionBehaviorStationary Unaffected by exposé.  Stays visible and stationary, like desktop window.
 *
 * @discussion You may specify at most one of \c NSWindowCollectionBehaviorParticipatesInCycle or \c NSWindowCollectionBehaviorIgnoresCycle.  If unspecified, the window gets the default behavior determined by its window level.
 *
 * @const NSWindowCollectionBehaviorParticipatesInCycle Default behavior if `windowLevel == NSNormalWindowLevel`.
 * @const NSWindowCollectionBehaviorIgnoresCycle Default behavior if `windowLevel != NSNormalWindowLevel`.
 *
 * @discussion You may specify at most one of \c NSWindowCollectionBehaviorFullScreenPrimary, \c NSWindowCollectionBehaviorFullScreenAuxiliary, or \c NSWindowCollectionBehaviorFullScreenNone.
 *
 * @const NSWindowCollectionBehaviorFullScreenPrimary The frontmost window with this collection behavior will be the fullscreen window.
 * @const NSWindowCollectionBehaviorFullScreenAuxiliary Windows with this collection behavior can be shown with the fullscreen window.
 * @const NSWindowCollectionBehaviorFullScreenNone The window can not be made fullscreen when this bit is set.
 *
 * @discussion You may specify at most one of \c NSWindowCollectionBehaviorFullScreenAllowsTiling or \c NSWindowCollectionBehaviorFullScreenDisallowsTiling, or an assertion will be raised.
 *
 * The default behavior is to allow any window to participate in full screen tiling, as long as it meets certain requirements, such as being resizable and not a panel or sheet. Windows which are not full screen capable can still become a secondary tile in full screen. A window can explicitly allow itself to be placed into a full screen tile by including \c NSWindowCollectionBehaviorFullScreenAllowsTiling. Even if a window allows itself to be placed in a tile, it still may not be put in the tile if its \c minFullScreenContentSize is too large to fit. A window can explicitly disallow itself from being placed in a full screen tile by including \c NSWindowCollectionBehaviorFullScreenDisallowsTiling. This is useful for non-full screen capable windows to explicitly prevent themselves from being tiled. It can also be used by a full screen window to prevent any other windows from being placed in its full screen tile.
 *
 * @const NSWindowCollectionBehaviorFullScreenAllowsTiling This window can be a full screen tile window. It does not have to have \c NSWindowCollectionBehaviorFullScreenPrimary set.
 * @const NSWindowCollectionBehaviorFullScreenDisallowsTiling This window can NOT be made a full screen tile window; it still may be allowed to be a regular \c NSWindowCollectionBehaviorFullScreenPrimary window.
 */
typedef NS_OPTIONS(NSUInteger, NSWindowCollectionBehavior) {
    NSWindowCollectionBehaviorDefault = 0,
    NSWindowCollectionBehaviorCanJoinAllSpaces = 1 << 0,
    NSWindowCollectionBehaviorMoveToActiveSpace = 1 << 1,
    
    NSWindowCollectionBehaviorManaged API_AVAILABLE(macos(10.6)) = 1 << 2,
    NSWindowCollectionBehaviorTransient API_AVAILABLE(macos(10.6)) = 1 << 3,
    NSWindowCollectionBehaviorStationary API_AVAILABLE(macos(10.6)) = 1 << 4,

    NSWindowCollectionBehaviorParticipatesInCycle API_AVAILABLE(macos(10.6)) = 1 << 5,
    NSWindowCollectionBehaviorIgnoresCycle API_AVAILABLE(macos(10.6)) = 1 << 6,
    
    NSWindowCollectionBehaviorFullScreenPrimary API_AVAILABLE(macos(10.7)) = 1 << 7,
    NSWindowCollectionBehaviorFullScreenAuxiliary API_AVAILABLE(macos(10.7)) = 1 << 8,
    NSWindowCollectionBehaviorFullScreenNone API_AVAILABLE(macos(10.7)) = 1 << 9,
    
    NSWindowCollectionBehaviorFullScreenAllowsTiling API_AVAILABLE(macos(10.11)) = 1 << 11,
    NSWindowCollectionBehaviorFullScreenDisallowsTiling API_AVAILABLE(macos(10.11)) = 1 << 12,
    
    NSWindowCollectionBehaviorPrimary API_AVAILABLE(macos(13.0)) = 1 << 16,
    NSWindowCollectionBehaviorAuxiliary API_AVAILABLE(macos(13.0)) = 1 << 17,
    NSWindowCollectionBehaviorCanJoinAllApplications API_AVAILABLE(macos(13.0)) = 1 << 18,
} API_AVAILABLE(macos(10.5));

/*!
 * @typedef NSWindowAnimationBehavior
 *
 * @const NSWindowAnimationBehaviorDefault  Let AppKit infer animation behavior for this window.
 * @const NSWindowAnimationBehaviorNone     Suppress inferred animations (don't animate).
 * @const NSWindowAnimationBehaviorDocumentWindow
 * @const NSWindowAnimationBehaviorUtilityWindow
 * @const NSWindowAnimationBehaviorAlertPanel
 */
typedef NS_ENUM(NSInteger, NSWindowAnimationBehavior) {
    NSWindowAnimationBehaviorDefault = 0,
    NSWindowAnimationBehaviorNone = 2,

    NSWindowAnimationBehaviorDocumentWindow = 3,
    NSWindowAnimationBehaviorUtilityWindow = 4,
    NSWindowAnimationBehaviorAlertPanel = 5
} API_AVAILABLE(macos(10.7));

/*!
 * @typedef NSWindowNumberListOptions
 *
 * Options used in `+windowNumbersWithOptions:`.  If no options are specified, the returned list contains window numbers for visible windows on the active space belonging to the calling application.
 *
 * @const NSWindowNumberListAllApplications
 * @const NSWindowNumberListAllSpaces
 */
typedef NS_OPTIONS(NSUInteger, NSWindowNumberListOptions) {
    NSWindowNumberListAllApplications = 1 << 0,
    NSWindowNumberListAllSpaces = 1 << 4
} API_AVAILABLE(macos(10.6));

/*!
 * @typedef NSWindowOcclusionState
 *
 * @const NSWindowOcclusionStateVisible If set, at least part of the window is visible. If not set, the entire window is occluded. Windows with non-rectangular shapes may be completely occluded on screen but still count as visible, if their bounding box falls into a visible region. Windows that are completely transparent may also still count as visible.
 */
typedef NS_OPTIONS(NSUInteger, NSWindowOcclusionState) {
    NSWindowOcclusionStateVisible = 1UL << 1,
} API_AVAILABLE(macos(10.9));

typedef NSInteger NSWindowLevel NS_TYPED_EXTENSIBLE_ENUM;
static const NSWindowLevel NSNormalWindowLevel = kCGNormalWindowLevel;
static const NSWindowLevel NSFloatingWindowLevel = kCGFloatingWindowLevel;
static const NSWindowLevel NSSubmenuWindowLevel = kCGTornOffMenuWindowLevel;
static const NSWindowLevel NSTornOffMenuWindowLevel = kCGTornOffMenuWindowLevel;
static const NSWindowLevel NSMainMenuWindowLevel = kCGMainMenuWindowLevel;
static const NSWindowLevel NSStatusWindowLevel = kCGStatusWindowLevel;
static const NSWindowLevel NSModalPanelWindowLevel = kCGModalPanelWindowLevel;
static const NSWindowLevel NSPopUpMenuWindowLevel = kCGPopUpMenuWindowLevel;
static const NSWindowLevel NSScreenSaverWindowLevel = kCGScreenSaverWindowLevel;

typedef NS_ENUM(NSUInteger, NSSelectionDirection) {
    NSDirectSelection = 0,
    NSSelectingNext,
    NSSelectingPrevious
};

/*!
 * @typedef NSWindowButton
 *
 * Standard window buttons.
 */
typedef NS_ENUM(NSUInteger, NSWindowButton) {
    NSWindowCloseButton,
    NSWindowMiniaturizeButton,
    NSWindowZoomButton,
    NSWindowToolbarButton,
    NSWindowDocumentIconButton,
    NSWindowDocumentVersionsButton API_AVAILABLE(macos(10.7)) = 6,
};

/*!
 * @typedef NSWindowTitleVisibility
 *
 * @const NSWindowTitleVisible  The default mode has a normal window title and titlebar buttons.
 * @const NSWindowTitleHidden The always hidden mode hides the title and moves the toolbar up into the area previously occupied by the title.
 */
typedef NS_ENUM(NSInteger, NSWindowTitleVisibility) {
    NSWindowTitleVisible = 0,
    NSWindowTitleHidden = 1,
} API_AVAILABLE(macos(10.10));

/*!
 * @typedef NSWindowToolbarStyle
 *
 * @const NSWindowToolbarStyleAutomatic The default value. The style will be determined by the window's given configuration.
 * @const NSWindowToolbarStyleExpanded The toolbar will appear below the window title.
 * @const NSWindowToolbarStylePreference For Settings windows only. The toolbar will appear below the window title and the items in the toolbar will attempt to have equal widths when possible.
 * @const NSWindowToolbarStyleUnified The window title will appear inline with the toolbar when visible.
 * @const NSWindowToolbarStyleUnifiedCompact Same as \c NSWindowToolbarStyleUnified, but with reduced margins in the toolbar allowing more focus to be on the contents of the window.
 */
typedef NS_ENUM(NSInteger, NSWindowToolbarStyle) {
    NSWindowToolbarStyleAutomatic,
    NSWindowToolbarStyleExpanded,
    NSWindowToolbarStylePreference,
    NSWindowToolbarStyleUnified,
    NSWindowToolbarStyleUnifiedCompact
} API_AVAILABLE(macos(11.0));

static const NSTimeInterval NSEventDurationForever = DBL_MAX;

typedef NS_ENUM(NSInteger, NSWindowUserTabbingPreference) {
    NSWindowUserTabbingPreferenceManual,
    NSWindowUserTabbingPreferenceAlways,
    NSWindowUserTabbingPreferenceInFullScreen,
} API_AVAILABLE(macos(10.12));

/*!
 * @typedef NSWindowTabbingMode
 *
 * @const NSWindowTabbingModeAutomatic The system automatically prefers to tab this window when appropriate.
 * @const NSWindowTabbingModePreferred The window explicitly should prefer to tab when shown.
 * @const NSWindowTabbingModeDisallowed The window explicitly should not prefer to tab when shown.
 */
typedef NS_ENUM(NSInteger, NSWindowTabbingMode) {
    NSWindowTabbingModeAutomatic,
    NSWindowTabbingModePreferred,
    NSWindowTabbingModeDisallowed
}  API_AVAILABLE(macos(10.12));

typedef NS_ENUM(NSInteger, NSTitlebarSeparatorStyle) {
    NSTitlebarSeparatorStyleAutomatic,
    NSTitlebarSeparatorStyleNone,
    NSTitlebarSeparatorStyleLine,
    NSTitlebarSeparatorStyleShadow
} API_AVAILABLE(macos(11.0));

typedef NSString * NSWindowFrameAutosaveName NS_SWIFT_BRIDGED_TYPEDEF;
typedef NSString * NSWindowPersistableFrameDescriptor NS_SWIFT_BRIDGED_TYPEDEF;
typedef NSString * NSWindowTabbingIdentifier NS_SWIFT_BRIDGED_TYPEDEF;

@interface NSWindow : NSResponder <NSAnimatablePropertyContainer, NSMenuItemValidation, NSUserInterfaceValidations, NSUserInterfaceItemIdentification, NSAppearanceCustomization, NSAccessibilityElement, NSAccessibility>

+ (NSRect)frameRectForContentRect:(NSRect)cRect styleMask:(NSWindowStyleMask)style;
+ (NSRect)contentRectForFrameRect:(NSRect)fRect styleMask:(NSWindowStyleMask)style;
+ (CGFloat)minFrameWidthWithTitle:(NSString *)title styleMask:(NSWindowStyleMask)style;
@property (class, readonly) NSWindowDepth defaultDepthLimit;

- (NSRect)frameRectForContentRect:(NSRect)contentRect;
- (NSRect)contentRectForFrameRect:(NSRect)frameRect;

- (instancetype)initWithContentRect:(NSRect)contentRect styleMask:(NSWindowStyleMask)style backing:(NSBackingStoreType)backingStoreType defer:(BOOL)flag NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithContentRect:(NSRect)contentRect styleMask:(NSWindowStyleMask)style backing:(NSBackingStoreType)backingStoreType defer:(BOOL)flag screen:(nullable NSScreen *)screen;
- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE; // Use initWithContentRect:. This method will throw an exception for coders that support allowsKeyedCoding, and is only available for compatibility with non keyed coding.

@property (copy) NSString *title;

/*!
 * Secondary text that may be displayed adjacent to or below the primary title depending on the configuration of the window.
 * A value of empty string will remove the subtitle from the window layout.
 */
@property (copy) NSString *subtitle API_AVAILABLE(macos(11.0));

/// See the enum values for how this property works.
@property NSWindowTitleVisibility titleVisibility API_AVAILABLE(macos(10.10)); // Default value is NSWindowTitleVisible

/// When \c YES, the titlebar doesn't draw its background, allowing all buttons to show through, and "click through" to happen. In general, this is only useful when \c NSFullSizeContentViewWindowMask is set.
@property BOOL titlebarAppearsTransparent API_AVAILABLE(macos(10.10));

/// Specifies how the titlebar area of the window should appear when the window displays an NSToolbar
@property NSWindowToolbarStyle toolbarStyle API_AVAILABLE(macos(11.0));

/// The \c contentLayoutRect will return the area inside the window that is for non-obscured content. Typically, this is the same thing as the `contentView`'s frame. However, for windows with the \c NSFullSizeContentViewWindowMask set, there needs to be a way to determine the portion that is not under the toolbar. The \c contentLayoutRect returns the portion of the layout that is not obscured under the toolbar. \c contentLayoutRect is in window coordinates. It is KVO compliant. */
@property (readonly) NSRect contentLayoutRect API_AVAILABLE(macos(10.10));

/// \c contentLayoutGuide is a corollary to \c contentLayoutRect. It can be used by autolayout constraints to automatically bind to the \c contentLayoutRect.
@property (nullable, readonly) id contentLayoutGuide API_AVAILABLE(macos(10.10));

/* The following methods allow you to add accessory views to the titlebar/toolbar area of a window. See NSTitlebarAccessoryViewController for more details.
 */
@property (copy) NSArray<__kindof NSTitlebarAccessoryViewController *> *titlebarAccessoryViewControllers API_AVAILABLE(macos(10.10));
- (void)addTitlebarAccessoryViewController:(NSTitlebarAccessoryViewController *)childViewController API_AVAILABLE(macos(10.10));
- (void)insertTitlebarAccessoryViewController:(NSTitlebarAccessoryViewController *)childViewController atIndex:(NSInteger)index API_AVAILABLE(macos(10.10));
/* NOTE: you can use this method, or removeFromParentViewController, which ever is easier. */
- (void)removeTitlebarAccessoryViewControllerAtIndex:(NSInteger)index API_AVAILABLE(macos(10.10));

/*!
 * If url is not nil and its path is not empty, the window will show a document icon in the titlebar.
 * If the url represents a filename or other resource with a known icon, that icon will be used as the document icon.  Otherwise the default document icon will be used.  The icon can be customized using `-[[NSWindow standardWindowButton:NSWindowDocumentIconButton] setImage:customImage]`.  If url is not nil and its path is not empty, the window will have a pop-up menu which can be shown via command-click on the area containing the document icon and title.  By default, this menu will display the path components of the url.  The presence and contents of this menu can be controlled by the delegate method `-[window:shouldPopUpDocumentPathMenu:]`
 * If the url is nil or has an empty path, the window will not show a document icon and will not have a pop-up menu available via command-click.
 */
@property (nullable, copy) NSURL *representedURL API_AVAILABLE(macos(10.5));
@property (copy) NSString *representedFilename;
- (void)setTitleWithRepresentedFilename:(NSString *)filename;
@property (getter=isExcludedFromWindowsMenu) BOOL excludedFromWindowsMenu;
@property (nullable, strong) __kindof NSView *contentView;
@property (nullable, weak) id<NSWindowDelegate> delegate;
@property (readonly) NSInteger windowNumber;

/// @note The styleMask can only be set on macOS 10.6 and later. Valid \c styleMask settings have the same restrictions as the \c styleMask passed to `-initWithContentRect:styleMask:backing:defer:`.  Some \c styleMask changes will cause the view hierarchy to be rebuilt, since there is a different subclass for the top level view of a borderless window than for the top level view of a titled window.
@property NSWindowStyleMask styleMask;

- (nullable NSText *)fieldEditor:(BOOL)createFlag forObject:(nullable id)object;
- (void)endEditingFor:(nullable id)object;

- (NSRect)constrainFrameRect:(NSRect)frameRect toScreen:(nullable NSScreen *)screen;
- (void)setFrame:(NSRect)frameRect display:(BOOL)flag;
- (void)setContentSize:(NSSize)size;
- (void)setFrameOrigin:(NSPoint)point;
- (void)setFrameTopLeftPoint:(NSPoint)point;
- (NSPoint)cascadeTopLeftFromPoint:(NSPoint)topLeftPoint;

/*!
 @abstract The frame to use when cascading or sizing a new window based on the receiver's position or size. This may be different from `frame` when the receiver is positioned by the system.
*/
@property (readonly) NSRect cascadingReferenceFrame API_AVAILABLE(macos(15.0));

@property (readonly) NSRect frame;

/*! Subclasses can override \c animationResizeTime: to control the total time for the frame change.
 \c newFrame is the rect passed into \c setFrame:display:animate:
 */
- (NSTimeInterval)animationResizeTime:(NSRect)newFrame;

/*! \c setFrame:display:animate: is equivalent to \c setFrame:display: if the \c animateFlag is NO.
    If the \c animationFlag is YES, this method will perform a smooth resize of the window, where the total time for the resize is specified by \c -animationResizeTime:
*/
- (void)setFrame:(NSRect)frameRect display:(BOOL)displayFlag animate:(BOOL)animateFlag;

@property (readonly) BOOL inLiveResize    API_AVAILABLE(macos(10.6));

@property NSSize resizeIncrements;
@property NSSize aspectRatio;

@property NSSize contentResizeIncrements;
@property NSSize contentAspectRatio;

@property BOOL viewsNeedDisplay;
- (void)displayIfNeeded;
- (void)display;

@property BOOL preservesContentDuringLiveResize;

- (void)update;

- (BOOL)makeFirstResponder:(nullable NSResponder *)responder;
/* firstResponder is Key Value Observing (KVO) compliant. */
@property (readonly, weak) NSResponder *firstResponder;

@property (readonly) NSEventModifierFlags resizeFlags;
- (void)close;
@property (getter=isReleasedWhenClosed) BOOL releasedWhenClosed;
- (void)miniaturize:(nullable id)sender;
- (void)deminiaturize:(nullable id)sender;
@property (getter=isZoomed, readonly) BOOL zoomed;
- (void)zoom:(nullable id)sender;
@property (getter=isMiniaturized, readonly) BOOL miniaturized;
- (BOOL)tryToPerform:(SEL)action with:(nullable id)object;
- (nullable id)validRequestorForSendType:(nullable NSPasteboardType)sendType returnType:(nullable NSPasteboardType)returnType;
@property (null_resettable, copy) NSColor *backgroundColor;

/* Indicates the thickness of a given border of the window. NSMinYEdge is the bottom edge of the window, while NSMaxYEdge is the top edge of the window. This method may throw an exception for values that don't apply to the current window styleMask; specifically, passing NSMaxYEdge for a non-textured window will always raise. The contentBorder does not include the titlebar or toolbar.
 */
- (void)setContentBorderThickness:(CGFloat)thickness forEdge:(NSRectEdge)edge API_AVAILABLE(macos(10.5));
- (CGFloat)contentBorderThicknessForEdge:(NSRectEdge)edge API_AVAILABLE(macos(10.5));

- (void)setAutorecalculatesContentBorderThickness:(BOOL)flag forEdge:(NSRectEdge)edge API_AVAILABLE(macos(10.5));
- (BOOL)autorecalculatesContentBorderThicknessForEdge:(NSRectEdge)edge API_AVAILABLE(macos(10.5));

/* Calling -setMovable with a flag of NO will disable server-side dragging of the window via titlebar or background.  -setMovableByWindowBackground:YES is ignored on a window that returns NO from -isMovable.  When a window returns NO for -isMovable, it can be assigned to a different space with its relative screen position preserved.  Note that a resizable window may still be resized, and the window frame may be changed programmatically.  Applications may choose to enable application-controlled window dragging after disabling server-side dragging (perhaps to achieve snapping or pinning) by handling the mouseDown/mouseDragged/mouseUp sequence in -sendEvent: in an NSWindow subclass.  Note that a non movable window will also not be moved (or resized) by the system in response to a display reconfiguration. */
@property (getter=isMovable) BOOL movable API_AVAILABLE(macos(10.6));

@property (getter=isMovableByWindowBackground) BOOL movableByWindowBackground;

@property BOOL hidesOnDeactivate;

/// Indicates whether a window can be hidden during `-[NSApplication hide:]`.  Default is \c YES.
@property BOOL canHide;

- (void)center;
- (void)makeKeyAndOrderFront:(nullable id)sender;
- (void)orderFront:(nullable id)sender;
- (void)orderBack:(nullable id)sender;
- (void)orderOut:(nullable id)sender;
- (void)orderWindow:(NSWindowOrderingMode)place relativeTo:(NSInteger)otherWin;
- (void)orderFrontRegardless;

@property (nullable, strong) NSImage *miniwindowImage;
@property (null_resettable, copy) NSString *miniwindowTitle;

@property (readonly, strong) NSDockTile *dockTile API_AVAILABLE(macos(10.5));

@property (getter=isDocumentEdited) BOOL documentEdited;
@property (getter=isVisible, readonly) BOOL visible;
@property (getter=isKeyWindow, readonly) BOOL keyWindow;
@property (getter=isMainWindow, readonly) BOOL mainWindow;
@property (readonly) BOOL canBecomeKeyWindow;
@property (readonly) BOOL canBecomeMainWindow;

/*! Makes the window key and main if eligible, updating NSApplication's `-keyWindow` and `-mainWindow` properties.
 */
- (void)makeKeyWindow;

/*! Makes the window main if eligible. Updates NSApplication's `-mainWindow` property.
 */
- (void)makeMainWindow;

/*! Informs the window that it has become the key window. This method exists as an override point. Do not invoke directly. Instead, invoke `-makeKeyWindow`.
 */
- (void)becomeKeyWindow;

/*! Informs the window that it has stopped being the key window. This method exists as an override point. Do not invoke directly. Windows automatically receive this message when deactivating or when another window has become key.
 */
- (void)resignKeyWindow;

/*! Informs the window that it has become the main window. This method exists as an override point. Do not invoke directly. Instead, invoke `-makeMainWindow`.
 */
- (void)becomeMainWindow;

/*! Informs the window that it has stopped being the main window. This method exists as an override point. Do not invoke directly. Windows automatically receive this message when deactivating or when another window has become main.
 */
- (void)resignMainWindow;

@property (readonly) BOOL worksWhenModal;

/// A Boolean value that indicates whether or not to prevent application termination when the receiving window is presented modally.
/// The value of this property is `YES` if the window should prevent application termination when modal; otherwise, `NO`.
/// The default value is `YES`. However, note that some window subclasses and some windows created indirectly (like those created by UI frameworks like AppKit and SwiftUI), may have different default values. For example, the Open panel and toolbar customization sheets should not prevent application termination, so those windows have `preventsApplicationTerminationWhenModal` set to `NO`. Some `NSAlert`s, like those that are simply informational, have windows that do not prevent application termination by default. Setting this property overrides the default behavior.
@property BOOL preventsApplicationTerminationWhenModal API_AVAILABLE(macos(10.6));

/* Methods to convert window coordinates to screen coordinates */
- (NSRect)convertRectToScreen:(NSRect)rect API_AVAILABLE(macos(10.7));
- (NSRect)convertRectFromScreen:(NSRect)rect API_AVAILABLE(macos(10.7));
- (NSPoint)convertPointToScreen:(NSPoint)point API_AVAILABLE(macos(10.12));
- (NSPoint)convertPointFromScreen:(NSPoint)point API_AVAILABLE(macos(10.12));

/* Methods to convert to/from a pixel integral backing store space */
- (NSRect)convertRectToBacking:(NSRect)rect API_AVAILABLE(macos(10.7));
- (NSRect)convertRectFromBacking:(NSRect)rect API_AVAILABLE(macos(10.7));
- (NSPoint)convertPointToBacking:(NSPoint)point API_AVAILABLE(macos(10.14));
- (NSPoint)convertPointFromBacking:(NSPoint)point API_AVAILABLE(macos(10.14));

/// Use `NSIntegralRectWithOptions()` to produce a backing store pixel aligned rectangle from the given input rectangle in window coordinates.
- (NSRect)backingAlignedRect:(NSRect)rect options:(NSAlignmentOptions)options API_AVAILABLE(macos(10.7));

/// Returns the scale factor representing the number of backing store pixels corresponding to each linear unit in window space on this \c NSWindow. This method is provided for rare cases when the explicit scale factor is needed. Please use `-convert*ToBacking:` methods whenever possible.
@property (readonly) CGFloat backingScaleFactor API_AVAILABLE(macos(10.7)); 

- (void)performClose:(nullable id)sender;
- (void)performMiniaturize:(nullable id)sender;
- (void)performZoom:(nullable id)sender;
- (NSData *)dataWithEPSInsideRect:(NSRect)rect;
- (NSData *)dataWithPDFInsideRect:(NSRect)rect;
- (void)print:(nullable id)sender;

/*!
 * Default is \c NO. Set to \c YES to allow a window to display tooltips even when the application is in the background.  Note that, enabling tooltips in an inactive application will cause the app to do work any time the mouse passes over the window.  This can degrade system performance.
 * Returns \c YES if this window displays tooltips even when the application is in the background.  To configure this setting you should call `-setAllowsToolTipsWhenApplicationIsInactive:` instead of overriding `-allowsToolTipsWhenApplicationIsInactive`.
 */
@property BOOL allowsToolTipsWhenApplicationIsInactive;

@property NSBackingStoreType backingType;
@property NSWindowLevel level;
@property NSWindowDepth depthLimit;
- (void)setDynamicDepthLimit:(BOOL)flag;
@property (readonly) BOOL hasDynamicDepthLimit;

/*! The screen property returns the best screen for the window. If the window only intersects one screen, it returns that screen. If it intersects more than one screen, then it resolves the tie through based on what space it is mostly on. It may return nil if there are no available screens, or it is completely off screen.
 */
@property (nullable, readonly, strong) NSScreen *screen;
@property (nullable, readonly, strong) NSScreen *deepestScreen;

@property BOOL hasShadow;
- (void)invalidateShadow;
@property CGFloat alphaValue;
@property (getter=isOpaque) BOOL opaque;


/*! `-setSharingType:` specifies whether the window content can be read from another process.  The default sharing type is \c NSWindowSharingReadOnly, which means other processes can read the window content (eg. for window capture) but cannot modify it.  If you set your window sharing type to \c NSWindowSharingNone, so that the content cannot be captured, your window will also not be able to participate in a number of system services, so this setting should be used with caution.
*/
@property NSWindowSharingType sharingType API_AVAILABLE(macos(10.5));

/*! Controls whether threading of view drawing should be enabled for this window.  Defaults to \c YES.  When this is set to \c YES, AppKit's view system is allowed to perform `-drawRect:` activity for the window's views on threads other than the main thread, for views that have `canDrawConcurrently == YES`.  When this is set to \c NO, the window's views will be drawn serially as on 10.5 and earlier, even though some of the views may have `canDrawConcurrently == YES`.
 */
@property BOOL allowsConcurrentViewDrawing API_AVAILABLE(macos(10.6));

@property BOOL displaysWhenScreenProfileChanges;

/*! This API controls whether the receiver is permitted onscreen before the user has logged in.  This property is off by default.  Alert panels and windows presented by input managers are examples of windows which should have this property set.
*/
@property BOOL canBecomeVisibleWithoutLogin API_AVAILABLE(macos(10.5));


@property NSWindowCollectionBehavior collectionBehavior API_AVAILABLE(macos(10.5));


/*! Provides for per-window control over automatic orderFront/orderOut animation behaviors added in 10.7.  Can be set to \c NSWindowAnimationBehaviorNone to disable Appkit's automatic animations for a given window, or to one of the other non-Default \c NSWindowAnimationBehavior values to override AppKit's automatic inference of appropriate animation behavior based on the window's apparent type.
*/
@property NSWindowAnimationBehavior animationBehavior API_AVAILABLE(macos(10.7));


/*! Returns \c YES if this window is associated with the active space.  For visible windows, this API indicates whether the window is currently visible on the active space.  For offscreen windows, it indicates whether ordering the window onscreen would make it bring it onto the active space */
@property (getter=isOnActiveSpace, readonly) BOOL onActiveSpace API_AVAILABLE(macos(10.6));

/*! `-toggleFullScreen:` enters or exits for full screen. A window must have \c NSWindowCollectionBehaviorFullScreenAuxiliary or \c NSWindowCollectionBehaviorFullScreenPrimary included in the \c collectionBehavior property; if it does not, this method may simply do nothing.
 */
- (void)toggleFullScreen:(nullable id)sender API_AVAILABLE(macos(10.7));

@property (readonly, copy) NSWindowPersistableFrameDescriptor stringWithSavedFrame;
- (void)setFrameFromString:(NSWindowPersistableFrameDescriptor)string;
- (void)saveFrameUsingName:(NSWindowFrameAutosaveName)name;
// Set force=YES to use setFrameUsingName on a non-resizable window
- (BOOL)setFrameUsingName:(NSWindowFrameAutosaveName)name force:(BOOL)force;
- (BOOL)setFrameUsingName:(NSWindowFrameAutosaveName)name;
- (BOOL)setFrameAutosaveName:(NSWindowFrameAutosaveName)name;
@property (readonly, copy) NSWindowFrameAutosaveName frameAutosaveName;
+ (void)removeFrameUsingName:(NSWindowFrameAutosaveName)name;

/* NOTE: minSize/contentMinSize and maxSize/contentMaxSize are ignored when using autolayout.
 */
@property NSSize minSize;
@property NSSize maxSize;
@property NSSize contentMinSize;
@property NSSize contentMaxSize;

/* These are the min and max values for a full screen tiled window.
 
 In general, one should not need to explicitly set the min/maxFullScreenContentSize. If an application does not change its window content upon entering full screen, then the normal auto layout min and max size will be sufficient, and one should not set these values. If an application does significantly rework the UI in full screen, then it may be necessary to set a min/maxFullScreenContentSize. This size is what is used to determine if a window can fit when it is in full screen in a tile. This property may be used even if the window does not support full screen, but are implicitly opted into supporting a full screen tile based on resizing behavior and window properties (see the collectionBehavior property). By default, the system uses auto layout to determine the min and max sizes. If auto layout is not used, contentMinSize and contentMaxSize are queried.
 */
@property NSSize minFullScreenContentSize API_AVAILABLE(macos(10.11));
@property NSSize maxFullScreenContentSize API_AVAILABLE(macos(10.11));

@property (readonly, copy) NSDictionary<NSDeviceDescriptionKey, id> *deviceDescription;

@property (nullable, weak) __kindof NSWindowController *windowController;

/*
 This API presents modal-sheets on this window. It replaces NSApp's -beginSheet:modalForWindow:modalDelegate:didEndSelector:contextInfo:.
 
 If the window already has a presented sheet, it will queue up sheets presented after that. Once the presented sheet is dismissed, the next queued sheet will be presented, and so forth.
 Critical sheets will skip this queuing process and be immediately presented on top of existing sheets. The presented sheet will be temporarily disabled and be able to be interacted with after the critical sheet is dismissed, and will then continue as normal. Critical sheets should only be used for time-critical or important events, when the presentation of the sheet needs to be guaranteed (Critical Alerts will automatically use this API).
*/
- (void)beginSheet:(NSWindow *)sheetWindow completionHandler:(void (^ _Nullable)(NSModalResponse returnCode))handler API_AVAILABLE(macos(10.9));
- (void)beginCriticalSheet:(NSWindow *)sheetWindow completionHandler:(void (^ _Nullable)(NSModalResponse returnCode))handler API_AVAILABLE(macos(10.9));
- (void)endSheet:(NSWindow *)sheetWindow API_AVAILABLE(macos(10.9));
- (void)endSheet:(NSWindow *)sheetWindow returnCode:(NSModalResponse)returnCode API_AVAILABLE(macos(10.9));

/// An ordered array of the sheets on the window. This consists of the presented sheets in top-to-bottom order, followed by queued sheets in the order they were queued. This does not include nested/sub-sheets.
@property (readonly, copy) NSArray<__kindof NSWindow *> *sheets API_AVAILABLE(macos(10.9));

/// Returns the top-most sheet if there is one or more sheets, or nil if there is no sheet.
@property (nullable, readonly, strong) NSWindow *attachedSheet;

@property (getter=isSheet, readonly) BOOL sheet;

/*!
 * Returns the window that the sheet is directly attached to. This is based on the logical attachment of the sheet, not visual attachment.
 * This relationship exists starting when the sheet is begun (using \c NSApplication's `-beginSheet:modalForWindow:modalDelegate:didEndSelector:contextInfo: or NSWindow's -beginSheet:completionHandler:`), and ending once it is ordered out.
 * Returns nil if the window is not a sheet or has no sheet parent.
 */
@property (nullable, readonly, strong) NSWindow *sheetParent API_AVAILABLE(macos(10.9));


+ (nullable NSButton *)standardWindowButton:(NSWindowButton)b forStyleMask:(NSWindowStyleMask)styleMask;
- (nullable NSButton *)standardWindowButton:(NSWindowButton)b;

- (void)addChildWindow:(NSWindow *)childWin ordered:(NSWindowOrderingMode)place;
- (void)removeChildWindow:(NSWindow *)childWin;
@property (nullable, readonly, copy) NSArray<__kindof NSWindow *> *childWindows;

@property (nullable, weak) NSWindow *parentWindow;

/// If set, the receiver will inherit the appearance of that object, as well as use KVO to observe its effectiveAppearance for changes. Typically this is used for child windows that are shown from a parent window or specific view. Defaults to NSApp.
@property (weak, null_resettable) NSObject<NSAppearanceCustomization> *appearanceSource API_AVAILABLE(macos(10.14));

@property (nullable, strong) NSColorSpace *colorSpace API_AVAILABLE(macos(10.6));

/*! `-canRepresentDisplayGamut:` returns \c YES if the colorSpace of the receiving window, and the \c colorSpace of the screen containing that window, are capable of representing the given display gamut
*/
- (BOOL)canRepresentDisplayGamut:(NSDisplayGamut)displayGamut  API_AVAILABLE(macos(10.12));

/*! `+windowNumbersWithOptions:` returns an autoreleased array of \c NSNumbers containing windowNumbers for all visible windows satisfying options.  If no options are specified, only visible windows belonging to the calling application and on the active space are included.  If options include \c NSWindowNumberListAllApplications, visible windows belonging to all applications are included.  If options include \c NSWindowNumberListAllSpaces, visible windows on all spaces are included.  Windows on the active space are returned in z-order.
   Examples: 
      To get an array of windowNumbers visible on the current space and belonging to the calling application:  
	`windowNumbers = [NSWindow windowNumbersWithOptions:0];`
      To get an array of windowNumbers visible on any space and belonging to any application:
	`windowNumbers = [NSWindow windowNumbersWithOptions:NSWindowNumberListAllApplications|NSWindowNumberListAllSpaces];`
      To get an array of windowNumbers visible on any space and belonging to the calling application:
	`windowNumbers = [NSWindow windowNumbersWithOptions:NSWindowNumberListAllSpaces];`
*/
+ (nullable NSArray<NSNumber *> *)windowNumbersWithOptions:(NSWindowNumberListOptions)options API_AVAILABLE(macos(10.6));

/*! `+windowNumberAtPoint:belowWindowWithWindowNumber:` returns the number of the frontmost window that would be hit by a mouseDown at the screen location "point".  "windowNum" can be specified to exclude a given window along with all windows above it, and may belong to any application.  If no windows are to be excluded, specify 0 for "windowNum".  The windowNumber returned may correspond to a window in another application.
*/
+ (NSInteger)windowNumberAtPoint:(NSPoint)point belowWindowWithWindowNumber:(NSInteger)windowNumber API_AVAILABLE(macos(10.6));

@property (readonly) NSWindowOcclusionState occlusionState API_AVAILABLE(macos(10.9));

/*! Specifies the style of separator displayed between the window's titlebar and content.
 
    The default value is NSTitlebarSeparatorStyleAutomatic. Changing this value will override any preference made by `NSSplitViewItem`.
 */
@property NSTitlebarSeparatorStyle titlebarSeparatorStyle API_AVAILABLE(macos(11.0));


#pragma mark - NSViewController Support

/*! The main content view controller for the window. This provides the contentView of the window. Assigning this value will remove the existing contentView and will make the contentViewController.view the main contentView for the window. The default value is nil. The contentViewController only controls the contentView, and not the title of the window. The window title can easily be bound to the contentViewController with the following: [window bind:NSTitleBinding toObject:contentViewController withKeyPath:@"title" options:nil]. Setting the contentViewController will cause the window to resize based on the current size of the contentViewController. Autolayout should be used to restrict the size of the window. The value of the contentViewController is encoded in the NIB. Directly assigning a contentView will clear out the contentViewController.
 */
@property (nullable, strong) NSViewController *contentViewController API_AVAILABLE(macos(10.10));

/*! Convenience method for creating an autoreleased titled window with the given contentViewController. A basic NSWindow with the following attributes is made: titled, closable, resizable, miniaturizable. The window's title is automatically bound to the contentViewController's title. The size of the window can easily be controlled by utilizing autolayout and applying size constraints to the view (or its subviews). The window has isReleasedWhenClosed set to NO, and it must be explicitly retained to keep the window instance alive. To have it automatically be freed when it is closed, do the following: [window retain] and [window setReleasedWhenClosed:YES].
 */
+ (instancetype)windowWithContentViewController:(NSViewController *)contentViewController API_AVAILABLE(macos(10.10));

#pragma mark - Window Dragging

/*! Call to start a drag (moving the window) in the Window Server process. In general, this can be done after a mouseDown event has come in and been examined by an application or view. The view may determine it wants to allow that portion of the window to start a window drag, and can hand off the work to the Window Server process by calling this method. This allows the window to participate in space switching, and other system features. Pass the original mouseDown event to the method. The method will return right away, and a mouseUp may not get sent.
 */
- (void)performWindowDragWithEvent:(NSEvent *)event API_AVAILABLE(macos(10.11));

#pragma mark - Keyboard UI support (Key View Loop)

@property (nullable, weak) NSView *initialFirstResponder;
- (void)selectNextKeyView:(nullable id)sender;
- (void)selectPreviousKeyView:(nullable id)sender;
- (void)selectKeyViewFollowingView:(NSView *)view;
- (void)selectKeyViewPrecedingView:(NSView *)view;
@property (readonly) NSSelectionDirection keyViewSelectionDirection;
@property (nullable, retain) NSButtonCell *defaultButtonCell;
- (void)disableKeyEquivalentForDefaultButtonCell;
- (void)enableKeyEquivalentForDefaultButtonCell;
@property BOOL autorecalculatesKeyViewLoop;
- (void)recalculateKeyViewLoop;

#pragma mark - Toolbar Support

@property (nullable, strong) NSToolbar *toolbar;
- (void)toggleToolbarShown:(nullable id)sender;
- (void)runToolbarCustomizationPalette:(nullable id)sender;
@property BOOL showsToolbarButton API_DEPRECATED("This property has no effect", macos(10.0, API_TO_BE_DEPRECATED));

#pragma mark - Automatic Window Tabbing

/*! Allows automatic window tabbing when the value is \c YES. By default, this will be set to \c YES, but applications can explicitly opt out of all automatic tabbing by setting it to NO, and can still adopted explicit window tabbing, if desired.
 */
@property (class) BOOL allowsAutomaticWindowTabbing API_AVAILABLE(macos(10.12));

/*! Returns the user's tabbing preference as set in System Preferences. This value should be queried anytime a new window is made to see if the user wants to automatically show it in tabs.
 */
@property (class, readonly) NSWindowUserTabbingPreference userTabbingPreference API_AVAILABLE(macos(10.12));

/*! Get and set the tabbing mode for this window. This should be set before a window is shown. The default value is \c NSWindowTabbingModeAutomatic. When the value is \c NSWindowTabbingModeAutomatic, the system will look at the \c userTabbingPreference and automatically tab windows together based on the tabbingIdentifier, when it is appropriate to do so.
 */
@property NSWindowTabbingMode tabbingMode API_AVAILABLE(macos(10.12));

/*! Windows with the same \c tabbingIdentifier will have the ability to be tabbed together when a window is being shown. This allows aggregation of similar windows. By default, the \c tabbingIdentifier will be generated based on inherent window properties, such as the window class name, the delegate class name, the window controller class name, and some additional state. Windows can be explicitly made to group together by using the same \c tabbingIdentifier.
 */
@property (copy) NSWindowTabbingIdentifier tabbingIdentifier API_AVAILABLE(macos(10.12));

/*! Actions that can be called to perform various tabbed window behaviors. UI that is hooked up to these items can be automatically validated by calling `NSWindow`'s \c validateUserInterfaceItem.
 */
- (IBAction)selectNextTab:(nullable id)sender API_AVAILABLE(macos(10.12));
- (IBAction)selectPreviousTab:(nullable id)sender API_AVAILABLE(macos(10.12));
- (IBAction)moveTabToNewWindow:(nullable id)sender API_AVAILABLE(macos(10.12));
- (IBAction)mergeAllWindows:(nullable id)sender API_AVAILABLE(macos(10.12));
- (IBAction)toggleTabBar:(nullable id)sender API_AVAILABLE(macos(10.12));

/*! Toggle the Tab Picker / Tab Overview UI which is invoked via "Show All Tabs". Performs the toggle in an animated fashion. Use `tabGroup.isOverviewVisible` to find out if it is visible or not at a given time.
 */
- (IBAction)toggleTabOverview:(nullable id)sender API_AVAILABLE(macos(10.13));

/*! This is now a cover for `self.tabGroup.windows`, but will return nil if the window is not showing a tab bar.
 */
@property (readonly, copy, nullable) NSArray<NSWindow *> *tabbedWindows API_AVAILABLE(macos(10.12));

/*! This is now a cover for `-[self.tabGroup addWindow:]`, which allows more precise placement.
 */
- (void)addTabbedWindow:(NSWindow *)window ordered:(NSWindowOrderingMode)ordered API_AVAILABLE(macos(10.12));

/*! Access the properties for this window when it is a tabbed window environment. See the \c NSWindowTab header and comments for more information.
 */
@property (strong, readonly) NSWindowTab *tab API_AVAILABLE(macos(10.13));

/*! Represents a tab group of windows. This \c tabGroup is lazily created on demand.
 */
@property (readonly, weak) NSWindowTabGroup *tabGroup API_AVAILABLE(macos(10.13));

#pragma mark - Window Sharing

/*!
     @abstract Attempt to move window sharing (i.e. within a SharePlay session) from the receiver to another window. In response to this request, the user may choose to transfer sharing to the new window, or simply stop sharing the content.
     @param window
        A window that is replacing the reciever in representing the user's current activity.
     @param completionHandler
        A completion block that is called after the request finishes.
        @c error
            In the event of a failed transfer request, a non-nil error contains details about the failure.
*/
- (void)transferWindowSharingToWindow:(NSWindow *)window completionHandler:(void(^)(NSError * _Nullable error))completionHandler API_AVAILABLE(macos(13.3));

/*!
 @abstract Indicates whether the receiver is the subject of an active SharePlay sharing session.
 */
@property (readonly) BOOL hasActiveWindowSharingSession API_AVAILABLE(macos(13.3));

/*!
 @abstract Request sharing of window.  If there is an available ScreenCaptureKit sharing session, an alert will be presented asking the user to confirm the share
 @param window
 The window to share
 @param completionHandler
 A completion block that is called after the request finishes.
 @c error
 The error will be non-nil if the request does not result in a window being shared.  The error will be NSUserCancelledError if there is no ScreenCaptureKit session, or if the user rejects the offer to share.  If sharing fails for some other reason, the error will provide the details.
 */
- (void)requestSharingOfWindow:(NSWindow *)window completionHandler:(void (^)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME(requestSharingOfWindow(_:completionHandler:)) API_AVAILABLE(macos(15.0));

/*!
 @abstract Request sharing of window to be provided later.  If there is an available ScreenCaptureKit sharing session, an alert will be presented asking the user to confirm the share.  The delegate will be asked to provide the window to share via windowForSharingRequestFromWindow:
 @param image
 An image showing a preview of the window to share
 @param title
 The title to show in a confirmation dialog
 @param completionHandler
 A completion block that is called after the request finishes.
 @c error
 The error will be non-nil if the request does not result in a window being shared.  The error will be NSUserCancelledError if there is no ScreenCaptureKit session, or if the user rejects the offer to share.  If sharing fails for some other reason, the error will provide the details.
 */
- (void)requestSharingOfWindowUsingPreview:(NSImage *)image title:(NSString *)title completionHandler:(void (^)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME(requestSharingOfWindow(usingPreview:title:completionHandler:)) API_AVAILABLE(macos(15.0));

#pragma mark - Other

/*! Retrieve the layout direction of the window titlebar: this includes the standard window buttons (close/minimize/maximize buttons) and the title for this window. In general, this will return "right to left" (RTL) if the primary system language is RTL. The layout direction may be RTL even in applications that do not have a RTL language localization. This value should be utilized if an application uses titlebarAppearsTransparent and places controls underneath the titlebar.
 */
@property (readonly) NSUserInterfaceLayoutDirection windowTitlebarLayoutDirection API_AVAILABLE(macos(10.12));

#pragma mark -

@end

@interface NSWindow(NSEvent)
/*! Tracks events matching the supplied mask with the supplied tracking handler until the tracking handler explicitly terminates tracking. Each event is removed from the event queue then passed to the tracking handler. If a matching event does not exist in the event queue, then the main thread blocks in the specified runloop mode until an event of the requested type is received or the timeout expires. If the timeout expires, the tracking handler is called with a nil event. A negative timeout is interpreted as 0. Use \c NSEventDurationForever to never timeout. Tracking continues until `*stop` is set to \c YES. Calls to `-nextEventMatchingMask:…` are allowed inside the trackingHandler block. This method returns once tracking is terminated.
 */
- (void)trackEventsMatchingMask:(NSEventMask)mask timeout:(NSTimeInterval)timeout mode:(NSRunLoopMode)mode handler:(void (NS_NOESCAPE ^)(NSEvent *_Nullable event, BOOL *stop))trackingHandler API_AVAILABLE(macos(10.10));
- (nullable NSEvent *)nextEventMatchingMask:(NSEventMask)mask;
- (nullable NSEvent *)nextEventMatchingMask:(NSEventMask)mask untilDate:(nullable NSDate *)expiration inMode:(NSRunLoopMode)mode dequeue:(BOOL)deqFlag;
- (void)discardEventsMatchingMask:(NSEventMask)mask beforeEvent:(nullable NSEvent *)lastEvent;

- (void)postEvent:(NSEvent *)event atStart:(BOOL)flag;
- (void)sendEvent:(NSEvent *)event;
@property (nullable, readonly, strong) NSEvent *currentEvent;
@property BOOL acceptsMouseMovedEvents;
@property BOOL ignoresMouseEvents;
@property (readonly) NSPoint mouseLocationOutsideOfEventStream;
@end

@interface NSWindow(NSCursorRect)
- (void)disableCursorRects;
- (void)enableCursorRects;
- (void)discardCursorRects;
@property (readonly) BOOL areCursorRectsEnabled;
- (void)invalidateCursorRectsForView:(NSView *)view;
- (void)resetCursorRects;
@end

@interface NSWindow(NSDrag)

- (NSDraggingSession *)beginDraggingSessionWithItems:(NSArray<NSDraggingItem *> *)items event:(NSEvent *)event source:(id<NSDraggingSource>)source NS_SWIFT_NAME(beginDraggingSession(items:event:source:)) API_AVAILABLE(macos(15.0));

- (void)dragImage:(NSImage *)image at:(NSPoint)baseLocation offset:(NSSize)initialOffset event:(NSEvent *)event pasteboard:(NSPasteboard *)pboard source:(id)sourceObj slideBack:(BOOL)slideFlag API_DEPRECATED("Use -[NSWindow beginDraggingSessionWithItems:event:source:] instead.", macos(10.0, API_TO_BE_DEPRECATED));

- (void)registerForDraggedTypes:(NSArray<NSPasteboardType> *)newTypes;
- (void)unregisterDraggedTypes;
@end

API_AVAILABLE(macos(14.0))
@interface NSWindow (NSDisplayLink)
/*
    Returns a new display link whose callback will be invoked in-sync with the display the window is on. If the window is not on any display the callback will not be invoked.
*/
- (CADisplayLink *)displayLinkWithTarget:(id)target selector:(SEL)selector NS_SWIFT_NAME(displayLink(target:selector:));
@end

@protocol NSWindowDelegate <NSObject>
@optional
- (BOOL)windowShouldClose:(NSWindow *)sender NS_SWIFT_UI_ACTOR;
- (nullable id)windowWillReturnFieldEditor:(NSWindow *)sender toObject:(nullable id)client NS_SWIFT_UI_ACTOR;
- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize NS_SWIFT_UI_ACTOR;
- (NSRect)windowWillUseStandardFrame:(NSWindow *)window defaultFrame:(NSRect)newFrame NS_SWIFT_UI_ACTOR;
- (BOOL)windowShouldZoom:(NSWindow *)window toFrame:(NSRect)newFrame NS_SWIFT_UI_ACTOR;
- (nullable NSUndoManager *)windowWillReturnUndoManager:(NSWindow *)window NS_SWIFT_UI_ACTOR;

/*! Tells the delegate that the window is about to show a sheet, and gives the delegate a chance to customize the location of the sheet.
 */
- (NSRect)window:(NSWindow *)window willPositionSheet:(NSWindow *)sheet usingRect:(NSRect)rect NS_SWIFT_UI_ACTOR;

/*! If a window has a \c representedURL, the window will by default show a path popup menu for a command-click on a rectangle containing the window document icon button and the window title.  The window delegate may implement `-window:shouldPopupDocumentPathMenu:` to override `NSWindow`'s default behavior for path popup menu.  A return of \c NO will prevent the menu from being shown.  A return of \c YES will cause the window to show the menu passed to this method, which by default will contain a menuItem for each path component of the \c representedURL.  If the \c representedURL has no path components, the menu will have no menu items.  Before returning \c YES, the window delegate may customize the menu by changing the menuItems.  menuItems may be added or deleted, and each menuItem title, action, or target may be modified.
*/
- (BOOL)window:(NSWindow *)window shouldPopUpDocumentPathMenu:(NSMenu *)menu NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.5));

/*! The window delegate may implement `-window:shouldDragDocumentWithEvent:from:withPasteboard:` to override \c NSWindow document icon's default drag behavior.  The delegate can prohibit the drag by returning \c NO.  Before returning \c NO, the delegate may implement its own dragging behavior using `-[NSWindow dragImage:at:offset:event:pasteboard:source:slideBack:]`.  Alternatively, the delegate can enable a drag by returning \c YES, for example to override NSWindow's default behavior of prohibiting the drag of an edited document.  Lastly, the delegate can customize the pasteboard contents before returning \c YES.
*/
- (BOOL)window:(NSWindow *)window shouldDragDocumentWithEvent:(NSEvent *)event from:(NSPoint)dragImageLocation withPasteboard:(NSPasteboard *)pasteboard NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.5));

- (NSSize)window:(NSWindow *)window willUseFullScreenContentSize:(NSSize)proposedSize NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

- (NSApplicationPresentationOptions)window:(NSWindow *)window willUseFullScreenPresentationOptions:(NSApplicationPresentationOptions)proposedOptions NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! The default animation between a window and its fullscreen representation is a crossfade.  With knowledge of the layout of a window before and after it enters fullscreen, an application can do a much better job on the animation.  The following API allows a window delegate to customize the animation by providing a custom window or windows containing layers or other effects.  In order to manage windows on spaces, we need the window delegate to provide a list of windows involved in the animation.  If an application does not do a custom animation, this method can be unimplemented or can return nil.  `-window:startCustomAnimationToEnterFullScreenWithDuration:` will be called only if `-customWindowsToEnterFullScreenForWindow:` returns non-nil.
 */
- (nullable NSArray<NSWindow *> *)customWindowsToEnterFullScreenForWindow:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! The system has started its animation into fullscreen, including transitioning to a new space.  Start the window fullscreen animation immediately, and perform the animation with the given duration to  be in sync with the system animation.  This method is called only if `-customWindowToEnterFullScreenForWindow:` returned non-nil.
*/
- (void)window:(NSWindow *)window startCustomAnimationToEnterFullScreenWithDuration:(NSTimeInterval)duration NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! In some cases, the transition to enter fullscreen will fail, due to being in the midst of handling some other animation or user gesture.  We will attempt to minimize these cases, but believe there is a need for failure handling.  This method indicates that there was an error, and the application should clean up any work it may have done to prepare to enter fullscreen.  This message will be sent whether or not the delegate indicated a custom animation by returning non-nil from `-customWindowsToEnterFullScreenForWindow:`.
*/
- (void)windowDidFailToEnterFullScreen:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! The window is about to exit fullscreen mode.  The following API allows a window delegate to customize the animation when the window is about to exit fullscreen.  In order to manage windows on spaces, we need the window delegate to provide a list of windows involved in the animation.  If an application does not do a custom animation, this method can be unimplemented or can return nil. `-window:startCustomAnimationToExitFullScreenWithDuration:` will be called only if `-customWindowsToExitFullScreenForWindow:` returns non-nil.
*/
- (nullable NSArray<NSWindow *> *)customWindowsToExitFullScreenForWindow:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! The system has started its animation out of fullscreen, including transitioning back to the desktop space.  Start the window animation immediately, and perform the animation with the given duration to  be in sync with the system animation.  This method is called only if `-customWindowsToExitFullScreenForWindow:` returned non-nil.
*/
- (void)window:(NSWindow *)window startCustomAnimationToExitFullScreenWithDuration:(NSTimeInterval)duration NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! `-customWindowsToEnterFullScreenForWindow:onScreen:` will be called in place of `-customWindowsToEnterFullScreenForWindow:` if both are implemented.
 */
- (nullable NSArray<NSWindow *> *)customWindowsToEnterFullScreenForWindow:(NSWindow *)window onScreen:(NSScreen *)screen NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.9));

/*! `-window:startCustomAnimationToEnterFullScreenOnScreen:withDuration:` will be called in place of `-window:startCustomAnimationToEnterFullScreenWithDuration:` if both are implemented.
 */
- (void)window:(NSWindow *)window startCustomAnimationToEnterFullScreenOnScreen:(NSScreen *)screen withDuration:(NSTimeInterval)duration NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.9));

/*! In some cases, the transition to exit fullscreen will fail, due to being in the midst of handling some other animation or user gesture.  We will attempt to minimize these cases, but believe there is a need for failure handling.  This method indicates that there was an error, and the application should clean up any work it may have done to prepare to exit fullscreen.  This message will be sent whether or not the delegate indicated a custom animation by returning non-nil from `-customWindowsToExitFullScreenForWindow:`.
*/
- (void)windowDidFailToExitFullScreen:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! Windows entering the version browser will be resized to the size returned by this method. If either dimension of the returned size is larger than the \c maxPreferredFrameSize, the window will also be scaled down to ensure it fits properly in the version browser. Returned sizes larger than \c maxAllowedSize will be constrained to that size. If this method is not implemented, the version browser will use `-window:willUseStandardFrame:` to determine the resulting window frame size.
*/
- (NSSize)window:(NSWindow *)window willResizeForVersionBrowserWithMaxPreferredSize:(NSSize)maxPreferredFrameSize maxAllowedSize:(NSSize)maxAllowedFrameSize NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! Method called by `-[NSWindow encodeRestorableStateWithCoder:]` to give the delegate a chance to encode any additional state into the NSCoder.  This state is available in the NSCoder passed to `-restoreWindowWithIdentifier:state:handler:`. See the header `NSWindowRestoration.h` for more information.
*/
- (void)window:(NSWindow *)window willEncodeRestorableState:(NSCoder *)state NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! Method called by `-[NSWindow restoreStateWithCoder:]` to give the delegate a chance to restore its own state, which it may decode from the \c NSCoder. See the header `NSWindowRestoration.h` for more information.
*/
- (void)window:(NSWindow *)window didDecodeRestorableState:(NSCoder *)state NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));

/*! Preview representable activity items, used for sharing and collaboration.
*/
- (NSArray<id<NSPreviewRepresentableActivityItem>> *_Nullable)previewRepresentableActivityItemsForWindow:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(13.2)) API_UNAVAILABLE(ios);

/*! Method called to get the window to share once sharing is confirmed, after a request is initiated by requestSharingOfWindowUsingPreview:title:completionHandler:. Implement this on the delegate of the requesting window
 */
- (nullable NSWindow *)windowForSharingRequestFromWindow:(NSWindow *)window NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(15.0));

/* Notifications
*/
- (void)windowDidResize:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidExpose:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowWillMove:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidMove:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidBecomeKey:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidResignKey:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidBecomeMain:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidResignMain:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowWillClose:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowWillMiniaturize:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidMiniaturize:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidDeminiaturize:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidUpdate:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidChangeScreen:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidChangeScreenProfile:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidChangeBackingProperties:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7)); // added in 10.7.3
- (void)windowWillBeginSheet:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowDidEndSheet:(NSNotification *)notification NS_SWIFT_UI_ACTOR;
- (void)windowWillStartLiveResize:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.6));
- (void)windowDidEndLiveResize:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.6));
- (void)windowWillEnterFullScreen:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowDidEnterFullScreen:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowWillExitFullScreen:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowDidExitFullScreen:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowWillEnterVersionBrowser:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowDidEnterVersionBrowser:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowWillExitVersionBrowser:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowDidExitVersionBrowser:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.7));
- (void)windowDidChangeOcclusionState:(NSNotification *)notification NS_SWIFT_UI_ACTOR API_AVAILABLE(macos(10.9));
@end


/* Notifications */
APPKIT_EXTERN NSNotificationName NSWindowDidBecomeKeyNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidBecomeMainNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidChangeScreenNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidDeminiaturizeNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidExposeNotification;			// userInfo key:  @"NSExposedRect"
APPKIT_EXTERN NSNotificationName NSWindowDidMiniaturizeNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidMoveNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidResignKeyNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidResignMainNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidResizeNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidUpdateNotification;
APPKIT_EXTERN NSNotificationName NSWindowWillCloseNotification;
APPKIT_EXTERN NSNotificationName NSWindowWillMiniaturizeNotification;
APPKIT_EXTERN NSNotificationName NSWindowWillMoveNotification;
APPKIT_EXTERN NSNotificationName NSWindowWillBeginSheetNotification;
APPKIT_EXTERN NSNotificationName NSWindowDidEndSheetNotification;

/*! \c NSWindowDidChangeBackingPropertiesNotification is posted on 10.7.3 and later, when a window's \c backingScaleFactor and/or its \c colorSpace changes.  When running on a system version where this new notification is available, applications should use it instead of \c NSWindowDidChangeScreenProfileNotification to watch for changes to either of these backing store properties.  Many applications won't have any need to watch for this notification, but those that perform sophisticated color handling or manually manage their own caches of window-resolution-and/or/colorspace-appropriate bitmapped images will find this notification useful, as a prompt to invalidate their caches or schedule other reassessment for the new resolution and/or color space as needed.  The notification's userInfo dictionary specifies the window's previous \c backingScaleFactor and \c colorSpace.  You can compare these with the window's new \c backingScaleFactor and \c colorSpace at the time of the notification, to determine which of these two properties (potentially both) changed.
*/
APPKIT_EXTERN NSNotificationName const NSWindowDidChangeBackingPropertiesNotification API_AVAILABLE(macos(10.7)); // added in 10.7.3; userInfo keys: NSBackingPropertyOldScaleFactorKey, NSBackingPropertyOldColorSpaceKey

APPKIT_EXTERN NSString * const NSBackingPropertyOldScaleFactorKey API_AVAILABLE(macos(10.7)); // added in 10.7.3; an NSNumber
APPKIT_EXTERN NSString * const NSBackingPropertyOldColorSpaceKey API_AVAILABLE(macos(10.7));  // added in 10.7.3; an NSColorSpace


/*! \c NSWindowDidChangeScreenProfileNotification is posted when a window's display's color profile changes, or when the window moves to a display that has a different color profile.  When running on 10.7.3 or later, this notification is still posted for compatibility, but modern applications should instead watch for \c NSWindowDidChangeBackingPropertiesNotification, which is posted for both color space and resolution changes, and facilitates handling both in a single update and redisplay pass.
*/
APPKIT_EXTERN NSNotificationName NSWindowDidChangeScreenProfileNotification;

/*! \c NSWindowWillStartLiveResizeNotification is sent when the user starts a live resize operation via a mouseDown in the resize corner.  The notification will be sent before the window size is changed.  Note that this notification is sent once for a sequence of window resize operations
 */
APPKIT_EXTERN NSNotificationName const NSWindowWillStartLiveResizeNotification  API_AVAILABLE(macos(10.6));
/*! \c NSWindowDidEndLiveResizeNotification is sent after the user ends a live resize operation via a mouseUp in the resize corner.  The notification will be sent after the final window size change.    Note that this notification is sent once for a sequence of window resize operations
 */
APPKIT_EXTERN NSNotificationName const NSWindowDidEndLiveResizeNotification  API_AVAILABLE(macos(10.6));
APPKIT_EXTERN NSNotificationName const NSWindowWillEnterFullScreenNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowDidEnterFullScreenNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowWillExitFullScreenNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowDidExitFullScreenNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowWillEnterVersionBrowserNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowDidEnterVersionBrowserNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowWillExitVersionBrowserNotification API_AVAILABLE(macos(10.7));
APPKIT_EXTERN NSNotificationName const NSWindowDidExitVersionBrowserNotification API_AVAILABLE(macos(10.7));
/*! Upon receiving this notification, you can query the \c NSWindow for its current occlusion state. Note that this only notifies about changes in the state of the occlusion, not when the occlusion region changes. You can use this notification to increase responsiveness and save power, by halting any expensive calculations that the user can not see.
 */
APPKIT_EXTERN NSNotificationName const NSWindowDidChangeOcclusionStateNotification API_AVAILABLE(macos(10.9));

@interface NSWindow(NSDeprecated)

- (void)cacheImageInRect:(NSRect)rect API_DEPRECATED("This method shouldn’t be used as it doesn’t work in all drawing situations; instead, a subview should be used that implements the desired drawing behavior", macos(10.0,10.13));
- (void)restoreCachedImage API_DEPRECATED("This method shouldn’t be used as it doesn’t work in all drawing situations; instead, a subview should be used that implements the desired drawing behavior", macos(10.0,10.13));
- (void)discardCachedImage API_DEPRECATED("This method shouldn’t be used as it doesn’t work in all drawing situations; instead, a subview should be used that implements the desired drawing behavior", macos(10.0,10.13));

+ (void)menuChanged:(NSMenu *)menu API_DEPRECATED("This method does not do anything and should not be called.", macos(10.0,10.11));

/* gState is unused and should not be called.
 */
- (NSInteger)gState API_DEPRECATED("This method is unused and should not be called.", macos(10.0,10.10));

/* The base/screen conversion methods are deprecated in 10.7 and later. Please use one of convertRectToScreen:, convertRectFromScreen:, convertPointToScreen:, or convertPointFromScreen: instead.  */
- (NSPoint)convertBaseToScreen:(NSPoint)point API_DEPRECATED("Use -convertRectToScreen: or -convertPointToScreen: instead", macos(10.0,10.7));
- (NSPoint)convertScreenToBase:(NSPoint)point API_DEPRECATED("Use -convertRectFromScreen or -convertPointFromScreen: instead", macos(10.0,10.7));

/* This method is deprecated and should not be used by applications targeting Mac OS X 10.7 or later.
 The implementation of this method will always return 1.0.  Please use -convertRectToBacking: and -backingScaleFactor instead.
 */
- (CGFloat)userSpaceScaleFactor API_DEPRECATED("Use -convertRectToBacking: and -backingScaleFactor instead", macos(10.4,10.7));

- (void)useOptimizedDrawing:(BOOL)flag API_DEPRECATED("This method does not do anything and should not be called.", macos(10.0,10.10));

/* canStoreColor has not been needed or used in a while and is deprecated. */
- (BOOL)canStoreColor API_DEPRECATED("This method does not do anything and should not be called.", macos(10.0,10.10));

- (void)disableFlushWindow API_DEPRECATED("Use +[NSAnimationContext runAnimationGroup:completionHandler:] to perform atomic updates across runloop invocations.", macos(10.0,10.14));
- (void)enableFlushWindow API_DEPRECATED("Use +[NSAnimationContext runAnimationGroup:completionHandler:] to perform atomic updates across runloop invocations.", macos(10.0,10.14));
@property (getter=isFlushWindowDisabled, readonly) BOOL flushWindowDisabled API_DEPRECATED("Use +[NSAnimationContext runAnimationGroup:completionHandler:] to perform atomic updates across runloop invocations.", macos(10.0,10.14));
- (void)flushWindow API_DEPRECATED("Allow AppKit's automatic deferred display mechanism to take care of flushing any graphics contexts as needed.", macos(10.0,10.14));
- (void)flushWindowIfNeeded API_DEPRECATED("Allow AppKit's automatic deferred display mechanism to take care of flushing any graphics contexts as needed.", macos(10.0,10.14));
@property (getter=isAutodisplay) BOOL autodisplay API_DEPRECATED("Use +[NSAnimationContext runAnimationGroup:completionHandler:] to temporarily prevent AppKit's automatic deferred display mechanism from drawing.", macos(10.0,10.14));

/* Returns NSGraphicsContext used to render the receiver's content on the screen for the calling thread.
 */
@property (nullable, readonly, strong) NSGraphicsContext *graphicsContext API_DEPRECATED("Add instances of NSView to display content in a window.", macos(10.0,10.14));

@property (getter=isOneShot) BOOL oneShot API_DEPRECATED("This property does not do anything and should not be used", macos(10.0,10.14));

typedef NS_ENUM(NSUInteger, NSWindowBackingLocation) {
    NSWindowBackingLocationDefault = 0,        // System determines if window backing store is in VRAM or main memory
    NSWindowBackingLocationVideoMemory = 1,        // Window backing store is in VRAM
    NSWindowBackingLocationMainMemory = 2        // Window backing store is in main memory
} API_DEPRECATED("", macos(10.5,10.14));

@property NSWindowBackingLocation preferredBackingLocation API_DEPRECATED("This property does not do anything and should not be used", macos(10.5,10.14));
@property (readonly) NSWindowBackingLocation backingLocation API_DEPRECATED("This property does not do anything and should not be used", macos(10.5,10.14));

@property BOOL showsResizeIndicator API_DEPRECATED("This property does not do anything and should not be used.", macos(10.0,15.0));

- (nullable NSWindow *)initWithWindowRef:(void * /* WindowRef */)windowRef API_DEPRECATED("This method should not be used.", macos(10.0,15.0));
@property (readonly) void * /* WindowRef */windowRef NS_RETURNS_INNER_POINTER API_DEPRECATED("This method should not be used.", macos(10.0,15.0));

- (void)disableScreenUpdatesUntilFlush API_DEPRECATED("This method does not do anything and should not be called.", macos(10.0,15.0));

@end

/* Deprecated legacy style mask constants. Prefer to use NSWindowStyleMask values instead.
 */
static const NSWindowStyleMask NSBorderlessWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskBorderless", macos(10.0,10.12)) = NSWindowStyleMaskBorderless;
static const NSWindowStyleMask NSTitledWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskTitled", macos(10.0,10.12)) = NSWindowStyleMaskTitled;
static const NSWindowStyleMask NSClosableWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskClosable", macos(10.0,10.12)) = NSWindowStyleMaskClosable;
static const NSWindowStyleMask NSMiniaturizableWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskMiniaturizable", macos(10.0,10.12)) = NSWindowStyleMaskMiniaturizable;
static const NSWindowStyleMask NSResizableWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskResizable", macos(10.0,10.12)) = NSWindowStyleMaskResizable;
static const NSWindowStyleMask NSTexturedBackgroundWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskTexturedBackground", macos(10.0,10.12)) = NSWindowStyleMaskTexturedBackground;
static const NSWindowStyleMask NSUnifiedTitleAndToolbarWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskUnifiedTitleAndToolbar", macos(10.0,10.12)) = NSWindowStyleMaskUnifiedTitleAndToolbar;
static const NSWindowStyleMask NSFullScreenWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskFullScreen", macos(10.0,10.12)) = NSWindowStyleMaskFullScreen;
static const NSWindowStyleMask NSFullSizeContentViewWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskFullSizeContentView", macos(10.0,10.12)) = NSWindowStyleMaskFullSizeContentView;
static const NSWindowStyleMask NSUtilityWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskUtilityWindow", macos(10.0,10.12)) = NSWindowStyleMaskUtilityWindow;
static const NSWindowStyleMask NSDocModalWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskDocModalWindow", macos(10.0,10.12)) = NSWindowStyleMaskDocModalWindow;
static const NSWindowStyleMask NSNonactivatingPanelMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskNonactivatingPanel", macos(10.0,10.12)) = NSWindowStyleMaskNonactivatingPanel;
static const NSWindowStyleMask NSHUDWindowMask API_DEPRECATED_WITH_REPLACEMENT("NSWindowStyleMaskHUDWindow", macos(10.0,10.12)) = NSWindowStyleMaskHUDWindow;
static const NSWindowStyleMask NSUnscaledWindowMask API_DEPRECATED("NSUnscaledWindowMask is deprecated and has no effect. The scale factor for a window backing store is dynamic and dependent on the screen it is placed on.", macos(10.0,10.9)) = 1 << 11;

/* Deprecated window button constants
 */
static const NSWindowButton NSWindowFullScreenButton API_DEPRECATED("The standard window button for NSWindowFullScreenButton is always nil; use NSWindowZoomButton instead", macos(10.7,10.12)) = (NSWindowButton)7;

/* Deprecated window levels
 */
static const NSWindowLevel NSDockWindowLevel API_DEPRECATED("", macos(10.0,10.13)) = kCGDockWindowLevel;

static const NSWindowSharingType NSWindowSharingReadWrite NS_SWIFT_NAME(NSWindowSharingType.readWrite) API_DEPRECATED("Use NSWindowSharingReadOnly instead", macos(10.5, 15.0)) = (NSWindowSharingType)2;



API_UNAVAILABLE_END
NS_HEADER_AUDIT_END(nullability, sendability)

