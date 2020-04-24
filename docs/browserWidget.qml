
import QtQuick 2.0
import QtWebView 1.1
import QtQuick.Layouts 1.14

Rectangle{

    anchors.fill: parent
    color: "#000000"

    WebView {

            id: webView
            anchors.fill: parent
            anchors.centerIn: parent
            transform: Translate { y: 65 }
    }

    function setUrl(msg: string)  {
            webView.url=msg
    }

}


