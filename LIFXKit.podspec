Pod::Spec.new do |s|
  s.name         = "LIFXKit"
  s.version      = "0.6.2"

  s.summary      = "LIFXKit is the LIFX SDK for Objective-C."
  s.description  = <<-DESC
                   LIFXKit lets you control your LIFX lights from iOS or OS X.
                   DESC

  s.homepage     = "http://github.com/getsenic/lifx-objc/"
  s.license      = 'MIT'
  s.authors      = { "Nick Forge" => "nick@nickforge.com", "Lars Blumberg" => "lars@senic.com" }

  s.ios.deployment_target = '6.0'
  s.osx.deployment_target = '10.9'

  s.source       = { :git => "https://github.com/getsenic/lifx-objc.git", :tag => "v0.6.2" }

  s.public_header_files = 'LIFXKit/LIFXKit.h', 'LIFXKit/Classes-Common/LFX{Client,NetworkContext,Light,LightCollection,TaggedLightCollection,Types,HSBKColor,Target,Device}.h'
  s.ios.source_files  = 'LIFXKit/Classes-Common/*.{h,m}', 'LIFXKit/Classes-iOS/*.{h,m}', 'LIFXKit/Extensions/LFXExtensions.h', 'LIFXKit/Extensions/{Categories-Cocoa,Categories-UIKit,Functions,Macros}/*.{h,m}', 'LIFXKit/LIFXKit.h'
  s.osx.source_files  = 'LIFXKit/Classes-Common/*.{h,m}', 'LIFXKit/Classes-OSX/*.{h,m}', 'LIFXKit/Extensions/LFXExtensions.h', 'LIFXKit/Extensions/{Categories-Cocoa,Functions,Macros}/*.{h,m}', 'LIFXKit/LIFXKit.h'

  s.frameworks    = 'SystemConfiguration'
  s.libraries     = 'z'
  s.requires_arc = true

  s.dependency 'CocoaAsyncSocket', "~> 7.4"
end
