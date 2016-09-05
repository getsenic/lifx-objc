//
//  LFXLight.h
//  LIFX
//
//  Created by Nick Forge on 12/12/2013.
//  Copyright (c) 2013 LIFX Labs. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LFXNetworkContext;
@protocol LFXLightObserver;
#import "LFXDevice.h"
#import "LFXTypes.h"


@interface LFXLight : LFXDevice <LFXLightTarget>

// Tags
@property (nonatomic, readonly) NSArray /* NSString */ * _Nonnull tags;
@property (nonatomic, readonly) NSArray /* LFXTaggedLightCollection */ * _Nonnull taggedCollections;


// Most of these Light State and Light Control methods are declared in LFXLightTarget,
// so you can use the same methods on both LFXLight and LFXLightCollection objects.

// Light State
- (NSString * _Nullable)label;
- (LFXHSBKColor * _Nullable)color;
- (LFXPowerState)powerState;
- (LFXFuzzyPowerState)fuzzyPowerState;


// Light Control
- (void)setLabel:(NSString * _Nonnull)label;
- (void)setColor:(LFXHSBKColor * _Nonnull)color;
- (void)setColor:(LFXHSBKColor * _Nonnull)color overDuration:(NSTimeInterval)duration;
- (void)setPowerState:(LFXPowerState)powerState;


// Firmware Versions
- (NSString * __nullable)meshFirmwareVersion;
- (NSString * __nullable)wifiFirmwareVersion;
- (BOOL)meshFirmwareVersionIsAtLeast:(NSString * __nonnull)version;
- (BOOL)wifiFirmwareVersionIsAtLeast:(NSString * __nonnull)version;


// Observers
- (void)addLightObserver:(id <LFXLightObserver> __nonnull)observer;
- (void)removeLightObserver:(id <LFXLightObserver> __nonnull)observer;

@end


@protocol LFXLightObserver <NSObject>

@optional
- (void)light:(LFXLight * _Nonnull)light didChangeLabel:(NSString * _Nullable)label;
- (void)light:(LFXLight * _Nonnull)light didChangeColor:(LFXHSBKColor * _Nullable)color;
- (void)light:(LFXLight * _Nonnull)light didChangePowerState:(LFXPowerState)powerState;
- (void)light:(LFXLight * _Nonnull)light didChangeReachability:(LFXDeviceReachability)reachability;

- (void)light:(LFXLight * _Nonnull)light didChangeMeshFirmwareVersion:(NSString * _Nullable)meshFirmwareVersion;
- (void)light:(LFXLight * _Nonnull)light didChangeWifiFirmwareVersion:(NSString * _Nullable)wifiFirmwareVersion;

@end

