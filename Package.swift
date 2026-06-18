// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "26.24.2-RC"
let urlVersion: String = "26.24.2"
let checksum: String = "d12e22c2a16f8390c67529e2526e9b8ea8102fa06dfc715c43c2f71d85689a57"
let catnipVersion = Version(0, 0, 7)

let dependencies: [Target.Dependency] = [
    .product(name: "Catnip", package: "catnip-spm"),
    .product(name: "WebRTC", package: "WebRTC"),
    .product(name: "Lottie", package: "lottie-spm"),
    .product(name: "OpenSSL", package: "OpenSSL"),
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
        .package(url: "https://github.com/airbnb/lottie-spm.git", exact: "4.4.3"),
        .package(url: "https://github.com/krzyzanowskim/OpenSSL.git", from: "3.2.2000"),
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
