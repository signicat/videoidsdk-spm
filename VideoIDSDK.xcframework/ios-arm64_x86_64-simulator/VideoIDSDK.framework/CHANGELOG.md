# Change Log

----
## what's New
## 1.17.0

    New Features 

    - [VID-6041] - Automation deploy
    - [VID-5904] - Hide camera after video
    - [VID-6035] -  Persist and send failure data of a previous process
    - [VID-7155] Set onClose func open, avoid force unwrap
    qq
## 1.16.0

    New Features 

    - [VID-6843] - update capture session after fallback
                
## 1.15.0

    New Features 

    - [VID-6328] privacy manifest
        
## 1.14.1

    New Features 

    - [VID-7022] - fix black screen after retry
        
## 1.14.0

    New Features 

    - [VID-6727] -  fix help instructions not shown
        
## 1.13.0

    New Features 

    - [VID-6091] - alignt info biometric consent text to top
    - [VID-6559] - Set Lottie version higher than 4.1.2
    - [VID-6457] - Return code and message in old onError
    - [VID-6571 ] - Create builtInWideAngleCamera if any error appears
    - Ability to change BaseViewController status label text color using Style object
    
        
## 1.12.0

    New Features 

    - [VID-6457] - Return open error object to integrator
        
## 1.11.0

    New Features 

    - [VID-6091.3] - BiometricConsent set Optional
    - [VID-6091] - request consent inside
    - [VID-6153] - Send SDK exception
        
## 1.10.0

    New Features 

    - [VID-6038] - handle 503 error
    - [VID-5970] - Add autofocus forced true
    - [VID-6038.2] - handle 503 error
    - [VID-6178] - Handle libraries
    - [VID-5970] - Add autofocus to CheckResult
    - [VID-6291] - rename to eIDBiometricConsent
        
## 1.9.0

    New Features 

    - [VID-5839] - Country list sorted
    - [VID-6124.2] - Request biometric consent
    - [VID-6057] - Cocoapods lite version published
        
## 1.8.0

    New Features 

    - [VID-5782] - Resume video when foreground
    - [VID-1843] - Add weak self reference required        

## 1.7.0

    New Features 

    - [VID-5091] - show keyboard automatically
    - [VID-1843] - Improve audio behaivor
    - [VID-5603] - Hide missage connecting - simileID
    - [VID-5641] - Type error denying permissions
        
## 1.6.0

    New Features 

    - [VID-5597] - Add language to clientTerms
    - [VID-5336] - connection protocol fallback
    - [VID-5648] - not exclude arm64 on simulator
    - [VID-5645] - retries attempts fixed
    
## 1.5.0

    New Features 

    - [VID-4896] - send header language nil
    - remove stomp http header

## 1.4.0

    New Features 

    - [VID-3341] - Reconnections
    - [VID-5184] - send available cameras

## 1.3.0

    New Features 

    - [VID-5091] - show keyboard automatically

## 1.2.0

    New Features 

    - [VID-5240] - Fix wellDoneView constraints
    - [VID-5026] - update to lottie 4.0.0
    - [VID-5234] - Added option to preselect country by doc id

## 1.1.0

    New Features 

    - [VID-4743] - Fix close button instructions screen small devices
    - [VID-4390] - time tilt
    - [VID-5074.2] - Disable bitcode
    - [VID-5074] - Migrated to last version of WebRTC


## 1.0.17

    New Features 

    - [VID-5020] - SDK is not displaying ok
    - [VID-4993] - VideoIDSDKViewController set as open

## 1.0.16

    New Features 

    - [VID-5067] - ice connection state
    - [VID-4617] - warn poor connection


## 1.0.15

    New Features 

    - [VID-4999] - Update permissions screen
    - [VID-5183.2] - Remove tag nfc

## 1.0.14

    New Features 

    - [VID-4762] - XCFrameworks
    - [VID-4797] - Choose best camera for device
    - [VID-4824] - Attestation service

## 1.0.13

    New Features 

    - bandwidth is null if fast requirement.
    - add eager option.

## 1.0.12

    New Features 

    - Changed project name for sonar to SDK iOS 2.0.
    - VID-4205 "Send Framework version.

## 1.0.11

    New Features 

    - Add comment to reconnections... we aren't handling reconnections on iOS now.
    - Add new delegates for phaseStart, phaseFinished and onEvent.
    - Add ABI stability
    
## 1.0.10
    New Features 

    - VideoIDLiteSDK works

    Improvements 

    - clean unused code  call to videoid.sdkSettings
    - Update podspec and class to avoid error from gitlab import.
    
## 1.0.9
    New Features 

    - VideoIDLiteSDK works

    Improvements 

    - clean unused code  call to videoid.sdkSettings
    - re-connections  
    - Update podspec and class to avoid error from gitlab import.


## 1.0.8

    Improvements 

    - update check requierements 
    
    
## 1.0.7

    New Features 

    - Support for VideoID Medium 

    Improvements 

    - Update compilation version to Swift 5.5.2  in order to support Xcode 13.2.1  

    - Support for event MediaSource.TurnOff 

    Bug Fixes 

    - Fix crash after try to start again the video identification after error in Hologram phase  

## 1.0.6

1. ExternalReference new optional parameter in interactors

## 1.0.5

1. Custom notification support
2. Fixed issue about letters suport for Captcha OTP  

## 1.0.4

1. Fixed issue in camera session, that provocate a connection lost error

## 1.0.3

1. Fixed Audio issue in WebRTC protocol

## 1.0.2

1. Re name Enviorment by SDK Enviorment

## 1.0.1

1. Fix Audio accelerate issue

## 1.0.0 

1. First SDK  Release 
