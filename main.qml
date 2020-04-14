import QtQuick 2.2
import QtQuick.Window 2.2



Window {
    visible: true
    width: 500
    height: 700
    color: "#bb8888"
    property alias scoretotalText: scoretotal.text
    title: qsTr("2048 par Lhamap et Khayne")

    Grid {
        id: grid
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 4
        anchors.topMargin: 203
        anchors.fill: parent
        spacing: 4
        rows: 4
        columns: 4
        focus: true
        Keys.onPressed:{
            switch (event.key) {
            case Qt.Key_Up:
                if(!vueGrid.mvtinutile(0)){
                    vueGrid.up();
                    vueGrid.generer();
                    vueGrid.update();}
                break;
            case Qt.Key_Down:
                if(!vueGrid.mvtinutile(1)){
                    vueGrid.down();
                    vueGrid.generer();
                    vueGrid.update();
                }
                break;
            case Qt.Key_Left:
                if(!vueGrid.mvtinutile(2)){
                    vueGrid.left();
                    vueGrid.generer();
                    vueGrid.update();}
                break;
            case Qt.Key_Right:
                if(!vueGrid.mvtinutile(3)){
                    vueGrid.right();
                    vueGrid.generer();
                    vueGrid.update();}
                break;
            }

        }

        Rectangle {
            id: c1
            width: 120
            height: 120
            color: vueGrid.o1x1QML
            radius: 5
            border.width: 0

            Text {
                id: t1
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c1x1QML
                focus : true
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50

            }
        }

        Rectangle {
            id: c2
            width: 120
            height: 120
            color: vueGrid.o1x2QML
            radius: 5
            border.width: 0
            Text {
                id: t2
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c1x2QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c3
            width: 120
            height: 120
            color: vueGrid.o1x3QML
            radius: 5
            border.width: 0
            Text {
                id: t3
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c1x3QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c4
            width: 120
            height: 120
            color: vueGrid.o1x4QML
            radius: 5
            border.width: 0
            Text {
                id: t4
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c1x4QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c5
            width: 120
            height: 120
            color: vueGrid.o2x1QML
            radius: 5
            border.width: 0
            Text {
                id: t5
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c2x1QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c6
            width: 120
            height: 120
            color: vueGrid.o2x2QML
            radius: 5
            border.width: 0
            Text {
                id: t6
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c2x2QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c7
            width: 120
            height: 120
            color: vueGrid.o2x3QML
            radius: 5
            border.width: 0
            Text {
                id: t7
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c2x3QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c8
            width: 120
            height: 120
            color: vueGrid.o2x4QML
            radius: 5
            border.width: 0
            Text {
                id: t8
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c2x4QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c9
            width: 120
            height: 120
            color: vueGrid.o3x1QML
            radius: 5
            border.width: 0
            Text {
                id: t9
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c3x1QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c10
            width: 120
            height: 120
            color: vueGrid.o3x2QML
            radius: 5
            border.width: 0
            Text {
                id: t10
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c3x2QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c11
            width: 120
            height: 120
            color: vueGrid.o3x3QML
            radius: 5
            border.width: 0
            Text {
                id: t11
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c3x3QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c12
            width: 120
            height: 120
            color: vueGrid.o3x4QML
            radius: 5
            border.width: 0
            Text {
                id: t12
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c3x4QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c13
            width: 120
            height: 120
            color: vueGrid.o4x1QML
            radius: 5
            border.width: 0
            Text {
                id: t13
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c4x1QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c14
            width: 120
            height: 120
            color: vueGrid.o4x2QML
            radius: 5
            border.width: 0
            Text {
                id: t14
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c4x2QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c15
            width: 120
            height: 120
            color: vueGrid.o4x3QML
            radius: 5
            border.width: 0
            Text {
                id: t15
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c4x3QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: c16
            width: 120
            height: 120
            color: vueGrid.o4x4QML
            radius: 5
            border.width: 0
            Text {
                id: t16
                x: 10
                y: 26
                width: 100
                height: 68
                text: vueGrid.c4x4QML
                font.pixelSize: 50
                horizontalAlignment: Text.AlignHCenter
            }
        }


        Rectangle {
            id: rectangle
            x: 12
            y: -90
            width: 220
            height: 75
            color: "#eeaaaa"
            radius: 5

            Text {
                id: score
                x: 0
                y: 0
                width: 220
                height: 45
                text: qsTr("Score :")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 22
            }
        }


        Text {
            id: scoretotal
            x: 12
            y: -55
            width: 220
            height: 30
            text: vueGrid.scoreQML
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
            focus : true
        }



        Rectangle {
            id: c17
            x: 20
            y: -170
            width: 150
            height: 60
            color: "#eeaaaa"
            radius: 5
            focus : true
            MouseArea {
                id: mouseArea
                x: 0
                y: 0
                width: 150
                height: 60
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: {
                    vueGrid.save();
                }
            }

            Text {
                id: t17
                x: 25
                y: 8
                width: 100
                height: 68
                text: "Sauvegarder"
                focus: true
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
            }
            border.width: 0


            Rectangle {
                id: c18
                x: 171
                y: 0
                width: 115
                height: 60
                color: "#eeaaaa"
                radius: 5
                focus : true
                Text {
                    id: t18
                    x: 8
                    y: 8
                    width: 100
                    height: 68
                    text: "Charger"
                    focus: true
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                }

                MouseArea {
                    id: mouseArea2
                    x: 0
                    y: 0
                    width: 115
                    height: 60
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: {
                        vueGrid.charge();
                    }
                }
                border.width: 0
            }

            Rectangle {
                id: c19
                x: 308
                y: 0
                width: 150
                height: 60
                color: "#eeaaaa"
                radius: 5
                focus: true
                MouseArea {
                    id: mouseArea1
                    x: 0
                    y: 0
                    width: 150
                    height: 60
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: {
                        vueGrid.reset();
                    }
                }

                Text {
                    id: t19
                    x: 25
                    y: 8
                    width: 100
                    height: 68
                    text: "Reset"
                    focus: true
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                }
                border.width: 0
            }

        }

    }

    Text {
        id: element
        x: 259
        y: 132
        width: 220
        height: 40
        text: vueGrid.defeatQML
        font.pixelSize: 22
    }
}
