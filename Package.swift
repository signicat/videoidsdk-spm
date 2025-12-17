// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "1.49.0-RC"
let urlVersion: String = "1.49.0"
let checksum: String = "1361f61043dc4a7b5e0b96eb65bbbcd4d3316bfed3a5814abb3fd4090dc6bb91"


let package = Package(
    name: "VideoIDSDK",
    platforms: [.iOS("15.1"),
                .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "VideoIDSDK",
            targets: ["VideoIDSDK", "_VideoIDSDKStub"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "VideoIDSDK",
            url: "https://eid-librerias-ios.s3.eu-west-1.amazonaws.com/VideoID-sdk/\(urlVersion)/VideoIDSDK.xcframework.zip",
            checksum: checksum),
        .target(name: "_VideoIDSDKStub",
                swiftSettings: [
                    .define("PLATFORM_IOS_ONLY", .when(platforms: [.iOS]))
                ])
    ]
)
