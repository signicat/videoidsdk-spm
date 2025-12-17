// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "1.49.0-RC"
let urlVersion: String = "1.49.0"
let checksum: String = "83a095a7a5f14e8dc09a34ac51dac6b5fcccaa8e05b0dec3bc7c609b90c15a8e"


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
