// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let version: String = "26.48.0-RC"
let urlVersion: String = "26.48.0"
let checksum: String = "13d09a1357f7b2d7c92b818546df47b07b74b23c262f667c53fcc102b38f840d"
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
        .package(url: "https://github.com/stasel/WebRTC.git", exact: "157.0.0"),
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
