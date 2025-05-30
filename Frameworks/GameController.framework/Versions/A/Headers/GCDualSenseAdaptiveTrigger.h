//  
//  GCDualSenseAdaptiveTrigger.h
//  GameController
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <GameController/GCControllerButtonInput.h>

NS_ASSUME_NONNULL_BEGIN

enum {
    /** The number of discrete control positions supported by the DualSense adaptive triggers. Each of these positions can be configured separately in multi-position feedback and multi-position vibration modes. */
    GCDualSenseAdaptiveTriggerDiscretePositionCount NS_SWIFT_NAME(GCDualSenseAdaptiveTrigger.discretePositionCount) API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4)) = 10,
};

typedef NS_ENUM(NSInteger, GCDualSenseAdaptiveTriggerMode) {
    /** The adaptive trigger effect is disabled. */
    GCDualSenseAdaptiveTriggerModeOff = 0,
    /** The adaptive trigger effect provides constant feedback from the start position onwards. */
    GCDualSenseAdaptiveTriggerModeFeedback = 1,
    /** The adaptive trigger effect provides feedback from the start position to the end position, emulating the feeling of pulling the trigger on a weapon. */
    GCDualSenseAdaptiveTriggerModeWeapon = 2,
    /** The adaptive trigger effect provides a constant vibration effect from the start position onwards. */
    GCDualSenseAdaptiveTriggerModeVibration = 3,
    /** The adaptive trigger effect provides feedback from the start position to the end position, linearly interpolated between the start and end strengths. */
    GCDualSenseAdaptiveTriggerModeSlopeFeedback API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4)) = 4
} NS_SWIFT_NAME(GCDualSenseAdaptiveTrigger.Mode) API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5));

typedef NS_ENUM(NSInteger, GCDualSenseAdaptiveTriggerStatus) {
    /** The adaptive trigger status cannot be determined. */
    GCDualSenseAdaptiveTriggerStatusUnknown = -1,
    /** The adaptive trigger is in feedback mode, and a resistive load has not been applied yet. */
    GCDualSenseAdaptiveTriggerStatusFeedbackNoLoad,
    /** The adaptive trigger is in feedback mode, and a resistive load is applied. */
    GCDualSenseAdaptiveTriggerStatusFeedbackLoadApplied,
    /** The adaptive trigger is in weapon mode, the trigger is ready to fire, and a resistive load has not been applied yet. */
    GCDualSenseAdaptiveTriggerStatusWeaponReady,
    /** The adaptive trigger is in weapon mode, the trigger is firing, and a resistive load is currently being applied. */
    GCDualSenseAdaptiveTriggerStatusWeaponFiring,
    /** The adaptive trigger is in weapon mode, the trigger has fired, and a resistive load is no longer being applied. */
    GCDualSenseAdaptiveTriggerStatusWeaponFired,
    /** The adaptive trigger is in vibration mode, and the trigger is not vibrating. */
    GCDualSenseAdaptiveTriggerStatusVibrationNotVibrating,
    /** The adaptive trigger is in vibration mode, and the trigger is currently vibrating. */
    GCDualSenseAdaptiveTriggerStatusVibrationIsVibrating,
    /** The adaptive trigger is in slope feedback mode, the trigger is ready to apply a resistive load, but a resistive load has not been applied yet. */
    GCDualSenseAdaptiveTriggerStatusSlopeFeedbackReady API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5)),
    /** The adaptive trigger is in slope feedback mode, and a resistive load is currently being applied to the trigger. */
    GCDualSenseAdaptiveTriggerStatusSlopeFeedbackApplyingLoad API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5)),
    /** The adaptive trigger is in slope feedback mode, a resistive load has previously been applied, but is no longer being applied. */
    GCDualSenseAdaptiveTriggerStatusSlopeFeedbackFinished API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5)),
} NS_SWIFT_NAME(GCDualSenseAdaptiveTrigger.Status) API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5));

typedef struct {
    /** An array of amplitudes associated with the GCDualSenseAdaptiveTriggerDiscretePositionCount control positions supported by the DualSense adaptive triggers. */
    float values[GCDualSenseAdaptiveTriggerDiscretePositionCount];
} GCDualSenseAdaptiveTriggerPositionalAmplitudes NS_SWIFT_NAME(GCDualSenseAdaptiveTrigger.PositionalAmplitudes) API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4));

typedef struct {
    /** An array of resistive strengths associated with the GCDualSenseAdaptiveTriggerDiscretePositionCount control positions supported by the DualSense adaptive triggers. */
    float values[GCDualSenseAdaptiveTriggerDiscretePositionCount];
} GCDualSenseAdaptiveTriggerPositionalResistiveStrengths NS_SWIFT_NAME(GCDualSenseAdaptiveTrigger.PositionalResistiveStrengths) API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4));

/**
 DualSense triggers are required to be analog inputs. Common uses would be acceleration and decelleration in a driving game for example.
 
 GCDualSenseAdaptiveTrigger represents an adaptive trigger on the Sony DualSense controller, allowing you to specify a dynamic resistance force
 that is applied when pulling the trigger. This can, for example, be used to emulate the feeling of pulling back a bow string, firing a weapon, or pulling a lever.
 
 @see GCDualSenseGamepad
 */
API_AVAILABLE(macos(11.3), ios(14.5), tvos(14.5))
@interface GCDualSenseAdaptiveTrigger : GCControllerButtonInput

/**
 The mode that the adaptive trigger is currently in. This property reflects the physical state of the triggers - and requires a response from the controller.
 It does not update immediately after calling -[GCDualSenseAdaptiveTrigger setMode...].
 
 @see GCDualSenseAdaptiveTriggerMode
 */
@property (nonatomic, readonly) GCDualSenseAdaptiveTriggerMode mode;

/**
 The current status of the adaptive trigger - whether it is ready to apply a load, is currently applying a load, or has finished applying a load.
 
 @see GCDualSenseAdaptiveTriggerStatus
 */
@property (nonatomic, readonly) GCDualSenseAdaptiveTriggerStatus status;

/**
 A normalized float from [0-1], with 0 representing the lowest possible trigger arm position and 1 representing the maximum trigger arm position.
 
 @see GCDualSenseAdaptiveTriggerStatus
 */
@property (nonatomic, readonly) float armPosition;

/**
 Sets the adaptive trigger to slope feedback mode. The start position, end position, start strength, and end strength of the effect can be set arbitrarily; however the end position must be larger than the start position.
 The trigger arm will provide a linearly interpolated degree of feedback whenever it is depressed between the start and end positions based on the starting and ending strengths.
 
 @param startPosition - A normalized float from [0-1], with 0 representing the smallest possible trigger depression and 1 representing the maximum trigger depression. The effect will begin once the trigger is depressed beyond this point.
 @param endPosition - A normalized float from [0-1], with 0 representing the smallest possible depression and 1 representing the maximum trigger depression. Must be greater than startPosition. The effect will end once the trigger is depressed beyond this point.
 @param startStrength - A normalized float from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength. The effect will begin at startStrength once the trigger is depressed beyond startPosition.
 @param endStrength - A normalized float from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength. The effect will end at endStrength once the trigger is depressed to endPosition.
 */
- (void)setModeSlopeFeedbackWithStartPosition:(float)startPosition endPosition:(float)endPosition startStrength:(float)startStrength endStrength:(float)endStrength API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4)) NS_SWIFT_NAME(setModeSlopeFeedback(startPosition:endPosition:startStrength:endStrength:));

/**
 Sets the adaptive trigger to feedback mode. The start position and strength of the effect can be set arbitrarily. The trigger arm will continue to provide a
 constant degree of feedback whenever it is depressed further than the start position.
 
 @param startPosition - A normalized float from [0-1], with 0 representing the smallest possible trigger depression and 1 representing the maximum trigger depression.
 @param resistiveStrength - A normalized float from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength.
 */
- (void)setModeFeedbackWithStartPosition:(float)startPosition resistiveStrength:(float)resistiveStrength;

/**
 Sets the adaptive trigger to feedback mode. The strength of the effect can be set for each possible trigger position. The trigger arm will provide a degree of feedback based on the resistive strength for a given position.
 
 @param positionalResistiveStrengths - Positional normalized floats from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength.
 */
- (void)setModeFeedbackWithResistiveStrengths:(GCDualSenseAdaptiveTriggerPositionalResistiveStrengths)positionalResistiveStrengths API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4)) NS_SWIFT_NAME(setModeFeedback(resistiveStrengths:));

/**
 Sets the adaptive trigger to weapon mode. The start position, end position, and strength of the effect can be set arbitrarily; however the end position must be larger than the start position.
 The trigger arm will continue to provide a constant degree of feedback whenever it is depressed further than the start position. Once the trigger arm has been depressed past the end
 position, the strength of the effect will immediately fall to zero, providing a "sense of release" similar to that provided by pulling the trigger of a weapon.
 
 @param startPosition - A normalized float from [0-1], with 0 representing the smallest possible depression and 1 representing the maximum trigger depression. The effect will begin once the trigger is depressed beyond this point.
 @param endPosition - A normalized float from [0-1], with 0 representing the smallest possible depression and 1 representing the maximum trigger depression. Must be greater than startPosition. The effect will end once the trigger is depressed beyond this point.
 @param resistiveStrength - A normalized float from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength.
 */
- (void)setModeWeaponWithStartPosition:(float)startPosition endPosition:(float)endPosition resistiveStrength:(float)resistiveStrength;

/**
 Sets the adaptive trigger to vibration mode. The start position, amplitude, and frequency of the effect can be set arbitrarily. The trigger arm will continue to strike against
 the trigger whenever it is depressed further than the start position, providing a "sense of vibration".
 
 @param startPosition - A normalized float from [0-1], with 0 representing the smallest possible depression and 1 representing the maximum trigger depression. The effect will begin once the trigger is depressed beyond this point.
 @param amplitude - A normalized float from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength.
 @param frequency - A normalized float from [0-1], with 0 representing the minimum frequency and 1 representing the maximum frequency of the vibration effect.
 */
- (void)setModeVibrationWithStartPosition:(float)startPosition amplitude:(float)amplitude frequency:(float)frequency;

/**
 Sets the adaptive trigger to vibration mode. The amplitude of the effect can be set for each possible trigger position. The trigger arm will provide a degree of feedback based on the amplitude for a given position. The trigger arm will continue to strike against the trigger, providing a "sense of vibration".
 
 @param positionalAmplitudes - Positional normalized floats from [0-1], with 0 representing the minimum effect strength (off entirely) and 1 representing the maximum effect strength.
 @param frequency - A normalized float from [0-1], with 0 representing the minimum frequency and 1 representing the maximum frequency of the vibration effect.
 */
- (void)setModeVibrationWithAmplitudes:(GCDualSenseAdaptiveTriggerPositionalAmplitudes)positionalAmplitudes frequency:(float)frequency API_AVAILABLE(macos(12.3), ios(15.4), tvos(15.4)) NS_SWIFT_NAME(setModeVibration(amplitudes:frequency:));

/**
 Sets the adaptive trigger to off mode. This turns off the adaptive trigger effect.
 */
- (void)setModeOff;

@end

NS_ASSUME_NONNULL_END
