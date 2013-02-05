//
//  IRenderingEngine.h
//  ArrowExample
//
//  Created by Dario Lencina on 2/3/13.
//  Copyright (c) 2013 Dario Lencina. All rights reserved.
//

// Physical orientation of a handheld device, equivalent to UIDeviceOrientation.
#import "Vector.hpp"

enum DeviceOrientation {
    DeviceOrientationUnknown,
    DeviceOrientationPortrait,
    DeviceOrientationPortraitUpsideDown,
    DeviceOrientationLandscapeLeft,
    DeviceOrientationLandscapeRight,
    DeviceOrientationFaceUp,
    DeviceOrientationFaceDown
};
// Creates an instance of the renderer and sets up various OpenGL state.

struct IRenderingEngine* CreateRenderer1();
struct IRenderingEngine* CreateRenderer2();

// Interface to the OpenGL ES renderer; consumed by GLView.

struct IRenderingEngine {
    virtual void Initialize(int width, int height) = 0;
    virtual void Render() const = 0;
    virtual void UpdateAnimation(float timeStep) = 0;
    virtual void OnRotate(DeviceOrientation newOrientation) = 0;
    virtual void OnFingerUp(ivec2 location) = 0;
    virtual void OnFingerDown(ivec2 location) = 0;
    virtual void OnFingerMove(ivec2 oldLocation, ivec2 newLocation) = 0;
    virtual ~IRenderingEngine() {}
};

