// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "26.42.3-RC"
let urlVersion: String = "26.42.3"
let checksum: String = "8e21a264b3e4981b9f466e6ed54e1abdfec2265315664da2312711d410dfee46"
let catnipVersion = Version(0, 0, 11)

let dependencies: [Target.Dependency] = [
    .product(name: "Catnip", package: "catnip-spm"),
    .product(name: "WebRTC", package: "WebRTC"),
    .product(name: "Lottie", package: "lottie-spm"),
]

let package = Package(
    name: "VideoIDSDK",
    platforms: [.iOS("15.1"),
                .macOS(.v10_15)],
    products: [
        .library(
            name: "VideoIDSDK",
            targets: ["VideoIDSDK", "_VideoIDSDKStub"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/signicat/catnip-spm.git", exact: catnipVersion),
        .package(url: "https://github.com/airbnb/lottie-spm.git", exact: "4.5.2"),
        .package(url: "https://github.com/stasel/WebRTC.git", exact: "134.0.0"),
    ],
    targets: [
        .binaryTarget(
            name: "VideoIDSDK",
            url: "https://eid-librerias-ios.s3.eu-west-1.amazonaws.com/VideoID-sdk/\(urlVersion)/VideoIDSDK.xcframework.zip",
            checksum: checksum
        ),
        .target(name: "_VideoIDSDKStub",
                dependencies: dependencies,
                swiftSettings: [
                    .define("PLATFORM_IOS_ONLY", .when(platforms: [.iOS])),
                ]),
    ]
)
