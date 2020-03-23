import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 500
    height: 500
    color: "#4c5cdc"
    title: qsTr("2048")

    Grid {
        id: grid
        anchors.leftMargin: 4
        anchors.topMargin: 4
        anchors.fill: parent
        spacing: 4
        rows: 4
        columns: 4
        focus: true
        Keys.onPressed:{
            switch (event.key) {
                case Qt.Key_Up:
                    break;
                case Qt.Key_Down:
                    break;
                case Qt.Key_Left:
                    break;
                case Qt.Key_Right:
                    break;
            }
        }

        Rectangle {
            id: c1
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0

            Text {
                id: t1
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue1x1.cptQML
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50
            }
        }

        Rectangle {
            id: c2
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t2
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue1x2.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c3
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t3
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue1x3.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c4
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t4
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue1x4.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c5
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t5
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue2x1.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c6
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t6
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue2x2.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c7
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t7
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue2x3.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c8
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t8
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue2x4.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c9
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t9
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue3x1.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c10
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t10
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue3x2.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c11
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t11
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue3x3.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c12
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t12
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue3x4.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c13
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t13
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue4x1.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c14
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t14
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue4x2.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c15
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t15
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue4x3.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c16
            width: 120
            height: 120
            color: "#ccccff"
            radius: 5
            border.width: 0
            Text {
                id: t16
                x: 10
                y: 26
                width: 100
                height: 68
                text: vue4x4.cptQML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
