
import QtQuick 2.0
import QtWebView 1.1

WebView {
        id: webView
        //anchors.fill: parent
        url: initialUrl
        onLoadingChanged: {
            if (loadRequest.errorString)
                console.error(loadRequest.errorString);
        }
    }



