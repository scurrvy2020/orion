#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include "singletonprovider.h"
#include <QSettings>

class SettingsManager : public QObject
{
    QML_SINGLETON
    Q_OBJECT

    Q_PROPERTY(bool alert READ alert WRITE setAlert NOTIFY alertChanged)
    Q_PROPERTY(bool closeToTray READ closeToTray WRITE setCloseToTray NOTIFY closeToTrayChanged)
    Q_PROPERTY(int alertPosition READ alertPosition WRITE setAlertPosition NOTIFY alertPositionChanged)
    Q_PROPERTY(int volumeLevel READ volumeLevel WRITE setVolumeLevel NOTIFY volumeLevelChanged)
    Q_PROPERTY(bool minimizeOnStartup READ minimizeOnStartup WRITE setMinimizeOnStartup NOTIFY minimizeOnStartupChanged)
    Q_PROPERTY(bool swapChat READ swapChat WRITE setSwapChat NOTIFY swapChatChanged)
    Q_PROPERTY(bool offlineNotifications READ offlineNotifications WRITE setOfflineNotifications NOTIFY offlineNotificationsChanged)
    Q_PROPERTY(double textScaleFactor READ textScaleFactor WRITE setTextScaleFactor NOTIFY textScaleFactorChanged)
    Q_PROPERTY(QString quality READ quality WRITE setQuality NOTIFY qualityChanged)
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(bool hasAccessToken READ hasAccessToken NOTIFY accessTokenChanged)

    bool mAlert;
    bool mCloseToTray;
    int mAlertPosition;
    int mVolumeLevel;
    bool mMinimizeOnStartup;
    bool mSwapChat;
    bool mOfflineNotifications;
    double mTextScaleFactor;
    QString mQuality;
    QString mAccessToken;

    explicit SettingsManager(QObject *parent = nullptr);
    static SettingsManager *instance;
public:
    static SettingsManager *getInstance();

    bool alert() const;
    void setAlert(bool alert);

    bool closeToTray() const;
    void setCloseToTray(bool closeToTray);

    int alertPosition() const;
    void setAlertPosition(int alertPosition);

    int volumeLevel() const;
    void setVolumeLevel(int volumeLevel);

    bool minimizeOnStartup() const;
    void setMinimizeOnStartup(bool minimizeOnStartup);

    bool swapChat() const;
    void setSwapChat(bool swapChat);

    bool offlineNotifications() const;
    void setOfflineNotifications(bool offlineNotifications);

    double textScaleFactor() const;
    void setTextScaleFactor(double textScaleFactor);

    QString quality() const;
    void setQuality(const QString &quality);

    QString accessToken() const;

signals:
    void alertChanged();
    void closeToTrayChanged();
    void alertPositionChanged();
    void volumeLevelChanged();
    void minimizeOnStartupChanged();
    void swapChatChanged();
    void offlineNotificationsChanged();
    void textScaleFactorChanged();
    void qualityChanged();
    void accessTokenChanged(QString accessToken);

public slots:
    void setAccessToken(const QString accessToken);
    bool hasAccessToken() const;
    void load();

    QString appName() const {
        return APP_NAME;
    }
    QString appVersion() const {
        return APP_VERSION;
    }

private:
    QSettings *settings;
};

#endif // SETTINGSMANAGER_H
