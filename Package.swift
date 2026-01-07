// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "1.49.0-RC"
let urlVersion: String = "1.49.0"
let checksum: String = "e7c2785439c19b50d56da6f88b43bb52150551134facf61ee608e7224f1fcc2b"


let package = Package(
    name: "VideoIDSDK",
    platforms: [.iOS("15.1"),
                .macOS(.v10_15)
    ],
    products: [
        .library(
            name: "VideoIDSDK",
            targets: ["_VideoIDSDKStub"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/airbnb/lottie-spm.git", exact: "4.4.3"),
        .package(url: "https://github.com/krzyzanowskim/OpenSSL.git", from: "3.2.2000"),
        .package(url: "https://github.com/stasel/WebRTC.git", exact: "134.0.0")
    ],
    targets: [
        .binaryTarget(
            name: "VideoIDSDK",
            url: "https://eid-librerias-ios.s3.eu-west-1.amazonaws.com/VideoID-sdk/\(urlVersion)/VideoIDSDK.xcframework.zip",
            checksum: checksum
        ),
        .target(
            name: "_VideoIDSDKStub",
            dependencies: [
                .target(name: "VideoIDSDK"),
                .product(name: "Lottie", package: "lottie-spm"),
                .product(name: "WebRTC", package: "WebRTC"),
                .product(name: "OpenSSL", package: "OpenSSL")
            ],
            path: "Sources/_VideoIDSDKStub",
            swiftSettings: [
                .define("PLATFORM_IOS_ONLY", .when(platforms: [.iOS]))
            ]
        )
    ]
)
