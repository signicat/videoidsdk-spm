
# VideoIDSDK

**Remote video identification made simple and compliant.**

`VideoIDSDK` is a Swift package that enables remote, asynchronous video identification compliant with European regulations such as **eIDAS** and **AML5**. Designed for seamless digital onboarding, the SDK leverages streaming video, AI-based document and face verification, and certified legal standards to offer secure and scalable identification without the need for in-person interaction.

---

## 🚀 Features

- ✅ Asynchronous video-based identity verification
- 🔐 AI-powered document and face validation
- 📱 Omnichannel experience — works on any device with a camera and internet access
- ⚖️ Fully compliant with eIDAS, SEPBLAC, AML5
- 🏦 Trusted by major financial institutions and public bodies
- 🌍 ISO 25000 certified; internationally patented

---

## 📦 Installation

### Swift Package Manager (Recommended)

In **Xcode**:

1. Go to `File` > `Add Packages…`
2. Enter the URL: https://github.com/signicat/videoidskd-spm.git
3. Choose the option:
- **Version: Up to Next Major** with starting version: `1.40.0`

This ensures you always get the latest compatible version (e.g., `1.41.0`, `1.99.0`, etc.), but never breaking changes unless you manually opt in.

4. Add `VideoIDSDK` to your target.

VideoIDSDK depends transitively on the binary Catnip SwiftPM package for shared runtime UI components. Xcode resolves and embeds `Catnip.framework` automatically when this package is added. App code should continue to import only `VideoIDSDK`; adding Catnip manually is not required.



Alternatively, add this to your `Package.swift`:

```swift
dependencies: [
 .package(url: "https://github.com/signicat/videoidskd-spm.git", from: "1.40.0")
]

📋 Requirements
    •    iOS 15.0+
    •    Xcode 16.0 or later
    •    Swift 5.3+
    
🔒 Compliance & Security
    •    Certified under ISO/IEC 25000 standards for software quality
    •    Patented technology for video-streaming-based identity verification
    •    eIDAS and AML5 compliance for KYC and digital onboarding

⸻

🧑‍💻 About Signicat

Signicat is a leader in digital identity and regulatory technology in Europe. Our VideoID solution is trusted by financial institutions, insurance companies, and governments for secure and seamless identity verification.

⸻

📄 License

This SDK is proprietary. Usage is subject to Signicat’s licensing terms. For commercial usage, please contact us via signicat.com.


⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻



## 🛠 USAGE

import VideoIDSDK

class VideoID {

    let headers = [
                "Accept": "Content-Type",
                "Authorization": "Bearer ...."
    ]

    let request = AuthorizationRequest(tenantId: "",
                                       process: "Unattended",
                                       rauthorityId: "",
                                       externalReference: nil,
                                       phone: nil)
    let serviceURL = Service.baseEndpoint + "videoid.request"

    restClient.postRequest(url: serviceURL,
                           headers: headers,
                           body: request,
                           onResult: { (authorization:AuthorizationResponse?) in
        
        if let auth = authorization {
            let environment = SDKEnvironment(url: Service.baseEndpoint, authorization: auth)

            let viewController = VideoIDSDK.VideoIDSDKViewController(environment: environment,
                                                           docType: nil,
                                                           language: "en",
                                                           docTypes: nil,
                                                           idDefault: nil,
                                                           biometricConsent: true) as VideoIDSDKViewController
            viewController.modalPresentationStyle = .overFullScreen
            viewController.delegate = self
            return viewController
        }
    })
}


class AuthorizationResponse: Decodable {
    var id: String?
    var authorization: String?
    
    enum CodingKeys: String, CodingKey {
        case id
        case authorization
    }
}
