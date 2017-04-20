#include "setting.h"

const QString Settings::_settingsFile = "./configs/settings.conf";


QML_Settings::QML_Settings(QObject* parent): QObject(parent)
{
    setDefaults();
}

void QML_Settings::setDefaults()
{
    QString defaultString;
    defaultString+= "TextViewer/TextMarkColor:230_209_209_255;";
    defaultString+= "TextViewer/ShowLectureText:true;";
    defaultString+= "TextViewer/ShowExampleText:true;";
    defaultString+= "TextViewer/ExampleSize:20;";
    defaultString+= "TextViewer/ExampleDiff:20;";
    Settings::setDefaults(defaultString);
}

Settings::Settings()
    : conf(_settingsFile, QSettings::NativeFormat){
    const QMetaObject &mo = staticMetaObject;
    int idx = mo.indexOfEnumerator("Key");
    keys = mo.enumerator(idx);

    idx = mo.indexOfEnumerator("Section");
    sections = mo.enumerator(idx);

}

QVariant Settings::get(Key k, Section s){
    Settings &self = instance();
    QString key = self.keyPath(s, k);
    return self.conf.value(key, self.defaults[key]);
}

Settings::ValueRef Settings::set(Key k, Section s){
    Settings &self = instance();
    return ValueRef(self, self.keyPath(s, k));
}

void Settings::setDefaults(const QString &str){
    Settings &self = instance();

    //section/key : value
    //section - optional
    QRegExp rxRecord("^\\s*(((\\w+)/)?(\\w+))\\s*:\\s*([^\\s].{0,})\\b\\s*$");

    auto kvs = str.split(QRegExp(";\\W*"), QString::SkipEmptyParts); //key-values
    for(auto kv : kvs){
        if(rxRecord.indexIn(kv) != -1){
            QString section = rxRecord.cap(3);
            QString key = rxRecord.cap(4);
            QString value = rxRecord.cap(5);

            int iKey = self.keys.keyToValue(key.toLocal8Bit().data());
            if(iKey != -1){
                int iSection = self.sections.keyToValue(section.toLocal8Bit().data());
                if(section.isEmpty() || iSection != -1){
                    self.defaults[rxRecord.cap(1)] = value;
                }
            }
        }
    }
}

//Settings::ValueRef-----------------------------------------------------------
Settings::ValueRef & Settings::ValueRef::operator = (const QVariant &data){
    parent.conf.setValue(keyPath, data);
    return *this;
}


//PRIVATE METHODS--------------------------------------------------------------
QString Settings::keyPath(Section s, Key k){
    auto szSection = sections.valueToKey(s);
    auto szKey = keys.valueToKey(k);
    return QString("%2/%1").arg(szKey).arg(szSection);
}

Settings & Settings::instance(){
    static Settings singleton;
    return singleton;
}
