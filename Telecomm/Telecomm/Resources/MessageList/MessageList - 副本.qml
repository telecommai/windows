import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4 as QC

import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import QtQuick.Controls.Styles 1.4


Item{
    id:rootItem
    objectName:"rootItem"
    //focus: true


    function doUpDownKeyClick(isUp)
    {
        if(isUp)
        {
            listViewMessageList.decrementCurrentIndex();

            listViewMessageList.currentItem.doClick();
        }else
        {
            listViewMessageList.incrementCurrentIndex();

            listViewMessageList.currentItem.doClick();
        }
    }

    function doClickIndex(index)
    {
        listViewMessageList.currentIndex = index;
        listViewMessageList.currentItem.doClick();
    }


    MouseArea{
        id:mouseAreaRoot
        anchors.fill: parent
        hoverEnabled: true

        QC.ScrollView{
            verticalScrollBarPolicy:  mouseAreaRoot.containsMouse? Qt.ScrollBarAsNeeded : Qt.ScrollBarAlwaysOff
            anchors.fill: parent



            style: ScrollViewStyle {

                handle: Rectangle {

                    implicitWidth: 20

                    implicitHeight: 30

                    color: "#063451"

                }

                scrollBarBackground: Rectangle {

                    implicitWidth: 10

                    implicitHeight: 30

                    color: "#09172c"

                }

                decrementControl: Rectangle {

                    implicitWidth: 10

                    implicitHeight: 0

                    color: "green"

                }

                incrementControl: Rectangle {

                    implicitWidth: 10

                    implicitHeight: 0

                    color: "blue"

                }

            }

            ListView {
                id: listViewMessageList
                objectName: "listViewMessageList"
                width: parent.width
                //keyNavigationWraps: true


                delegate:ItemDelegate {
                    width: parent.width
                    height: 58

                    function doClick()
                    {
                        listViewMessageList.currentIndex = index;
                        messageListModel.currentSelectedUserId = userId;
                        unreadMsgCount = 0;
                        messageList.doClickItem(userId);
                    }


                    Rectangle{
                        anchors.fill: parent
                        color: parent.ListView.isCurrentItem? "#183257":(mouseAreaFriendItem.containsMouse|| buttonRemove.hovered? "#092442":"#0a182d")
                    }

                    MouseArea{
                        id:mouseAreaFriendItem
                        anchors.fill: parent
                        hoverEnabled: true

                        onClicked: {
                            parent.doClick();
                        }

                        onEntered: {
                            //messageList.showToolTip(msg);
                        }

                        onExited: {
                            //messageList.showToolTip("");//隐藏显示
                        }
                    }


                    RowLayout {
                        id: rowLayout
                        anchors.fill: parent

                        Item {
                            id: item1
                            width: 55
                            Layout.fillHeight: true

                            Image {
                                id: imageHead
                                x: 8
                                width: 40
                                height: 40
                                anchors.verticalCenter: parent.verticalCenter
                                sourceSize.height: 40
                                sourceSize.width: 40
                                mipmap: true
                                //source: "file:///C:/OpenPlanet/resource/header/192210.png"
                                source:headUrl
                                asynchronous: true

                                layer.enabled: true
                                layer.effect: OpacityMask {
                                    maskSource: Item {
                                        width: imageHead.width
                                        height: imageHead.height
                                        Rectangle {
                                            anchors.centerIn: parent
                                            width: imageHead.width
                                            height: imageHead.height
                                            radius: 4
                                        }
                                    }
                                }
                            }
                        }

                        Item {
                            id: item2
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            clip:true

                            ColumnLayout {
                                id: columnLayout
                                spacing: 0
                                anchors.fill: parent

                                Item {
                                    id: item4
                                    Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true

                                    Label {
                                        id: labelNickName
                                        color: "#1381c6"
                                        anchors.fill: parent
                                        elide:Text.ElideRight
                                        verticalAlignment: Text.AlignBottom
                                        //text: qsTr("大西瓜大西瓜大西瓜大西瓜大西瓜大西瓜大西瓜大西瓜大西瓜")
                                        text:nickName
                                        anchors.bottom: parent.bottom
                                        anchors.bottomMargin: 0
                                        font.family:"microsoft yahei"
                                        //font.pixelSize:14
                                        //font.pointSize:13
                                        font.pointSize: Qt.platform.os == "osx"? 14:14*0.75
                                    }
                                }

                                Item {
                                    id: item5
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true

                                    Label {
                                        id: labelMsg
                                        anchors.fill: parent
                                        elide:Text.ElideRight
                                        verticalAlignment: Text.AlignTop
                                        //text: qsTr("今天下午有事，测试下程序开发哈哈哈，长度测试今天下午有事，测试下程序开发哈哈哈，长度测试今天下午有事，测试下程序开发哈哈哈，长度测试")
                                        text:msg
                                        color:"#3b5b7c"
                                        //font.pixelSize:12
                                        //font.pointSize:12
                                        font.pointSize: Qt.platform.os == "osx"? 12:12*0.75
                                        font.family:"microsoft yahei"
                                    }
                                }
                            }
                        }

                        Item {
                            id: item3
                            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                            Layout.fillHeight: true
                            width:labelMsgTime.contentWidth+5

                            ColumnLayout {
                                id: columnLayoutRight
                                spacing: 0
                                anchors.fill: parent

                                Item {
                                    id: item6
                                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true

                                    Label {
                                        id: labelMsgTime
                                        //text: qsTr("2018-09-09")
                                        text:msgTime
                                        anchors.right: parent.right
                                        anchors.rightMargin: 10
                                        verticalAlignment: Text.AlignBottom
                                        anchors.bottom: parent.bottom
                                        anchors.bottomMargin: 0
                                        color: "#1381c6"
                                        font.family:"microsoft yahei"
                                        //font.pixelSize:12
                                        //font.pointSize:12
                                        font.pointSize: Qt.platform.os == "osx"? 12:12*0.75
                                    }
                                }

                                Item {
                                    id: item7
                                    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                                    Layout.fillHeight: true
                                    Layout.fillWidth: true

                                    Rectangle {
                                        id: rectangle
                                        visible: !buttonRemove.visible && unreadMsgCount > 0
                                        width: 20
                                        height: 20
                                        color: "#ff7f24"
                                        radius: 10
                                        border.width: 0
                                        anchors.right: parent.right
                                        anchors.rightMargin: 10
                                        border.color: "#00000000"

                                        Label {
                                            id: label1
                                            //text: qsTr("88")
                                            text:unreadMsgCount.toString()
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            anchors.fill: parent
                                            //font.pixelSize: 10
                                            //font.pointSize:10
                                            font.family:"microsoft yahei"
                                            font.pointSize: Qt.platform.os == "osx"? 10:10*0.75
                                        }
                                    }

                                    Button {
                                        id: buttonRemove
                                        width: 20
                                        height: 20
                                        anchors.right: parent.right
                                        anchors.rightMargin: 10
                                        visible: mouseAreaFriendItem.containsMouse || buttonRemove.hovered
                                        hoverEnabled:true
                                        background: Image{
                                            anchors.fill: parent
                                            source: buttonRemove.hovered? "qrc:/Login/Resources/login/message_close.png" : "qrc:/Login/Resources/login/message_close_hove.png"
                                        }

                                        MouseArea{
                                            anchors.fill: parent
                                            cursorShape:Qt.PointingHandCursor
                                            //onPressed:  mouse.accepted = false
                                            acceptedButtons: Qt.NoButton
                                        }

                                        onClicked:{
                                            messageList.sigCloseChat(userId);

                                            //messageList.onDeleteItem(index);
                                        }
                                    }
                                }
                            }


                        }
                    }
                }



                model: messageListModel



                Component.onCompleted: {

                }


            }


        }
    }


}




