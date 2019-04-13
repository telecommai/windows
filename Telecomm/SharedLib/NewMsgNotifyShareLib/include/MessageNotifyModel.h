#ifndef MessageNotifyModel_H
#define MessageNotifyModel_H

#include <QAbstractListModel>
#include <QList>


class MessageNotifyItem
{
public:
	MessageNotifyItem(const int &msgCount, const QString &userId, const QString &headUrl, 
		const QString &nickName, const QString &lastMsg, const int &perMsgCount, const int &msgType, const int &funcType);

	int msgCount() const;
	QString userId() const;
	QString headUrl() const;
	QString nickName() const;
	QString lastMsg() const;
	int perMsgCount() const;
	int msgType() const;
	int funcType() const;

	void setMsgCount(QVariant val);
	void setUserId(QVariant val);
	void setHeadUrl(QVariant val);
	void setNickName(QVariant val);
	void setLastMsg(QVariant val);
	void setPerMsgCount(QVariant val);
	void setMsgType(QVariant val);
	void setFuncType(QVariant val);

private:
	int m_msgCount;
	QString m_userId;
	QString m_headUrl;
	QString m_nickName;
	QString m_lastMsg;
	int m_perMsgCount;
	int m_msgType;
	int m_funcType;
};

class MessageNotifyModel : public QAbstractListModel
{
	Q_OBJECT
public:
	enum MessageNotifyItemRoles {
		MsgCountRole,
		UserIdRole,
		HeadUrlRole,
		NickNameRole,
		LastMsgRole,
		PerMsgCountRole,
		MsgTypeRole,
		FuncTypeRole
	};

	MessageNotifyModel(QObject *parent = 0);


	void pushFront(const MessageNotifyItem *item);
	void pushBack(const MessageNotifyItem *item);
	void insertItem(const MessageNotifyItem *item, const int index);

	int rowCount(const QModelIndex & parent = QModelIndex()) const;

	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

	QString currentSelectedUserId();
	void setCurrentSelectedUserId(QString userId);

	Q_INVOKABLE void clear();
	Q_PROPERTY(QString currentSelectedUserId READ currentSelectedUserId WRITE setCurrentSelectedUserId);
	Q_INVOKABLE void takeItem(int row);

protected:
	QHash<int, QByteArray> roleNames() const;
private:
	QList<MessageNotifyItem> m_items;
	QString m_currentSelectedUserId;
};

#endif
