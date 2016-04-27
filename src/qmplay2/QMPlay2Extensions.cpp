#include <QMPlay2Extensions.hpp>

#include <QMPlay2Core.hpp>
#include <Module.hpp>

QList<QMPlay2Extensions *> QMPlay2Extensions::guiExtensionsList;

void QMPlay2Extensions::openExtensions()
{
	if (!guiExtensionsList.isEmpty())
		return;
	foreach (Module *module, QMPlay2Core.getPluginsInstance())
		foreach (const Module::Info &mod, module->getModulesInfo())
			if (mod.type == Module::QMPLAY2EXTENSION)
			{
				QMPlay2Extensions *QMPlay2Ext = (QMPlay2Extensions *)module->createInstance(mod.name);
				if (QMPlay2Ext)
					guiExtensionsList.append(QMPlay2Ext);
			}
	foreach (QMPlay2Extensions *QMPlay2Ext, guiExtensionsList)
		QMPlay2Ext->init();
}

void QMPlay2Extensions::closeExtensions()
{
	while (!guiExtensionsList.isEmpty())
		delete guiExtensionsList.takeFirst();
}

DockWidget *QMPlay2Extensions::getDockWidget()
{
	return NULL;
}

QList<QMPlay2Extensions::AddressPrefix> QMPlay2Extensions::addressPrefixList(bool img)
{
	Q_UNUSED(img)
	return QList<AddressPrefix>();
}
void QMPlay2Extensions::convertAddress(const QString &, const QString &, const QString &, QString *, QString *, QImage *, QString *extension, IOController<> *ioCtrl)
{
	Q_UNUSED(extension)
	Q_UNUSED(ioCtrl)
}

QAction *QMPlay2Extensions::getAction(const QString &, int, const QString &, const QString &prefix, const QString &param)
{
	Q_UNUSED(prefix)
	Q_UNUSED(param)
	return NULL;
}

bool QMPlay2Extensions::isVisualization() const
{
	return false;
}
void QMPlay2Extensions::connectDoubleClick(const QObject *, const char *)
{}
void QMPlay2Extensions::visState(bool, uchar chn, uint srate)
{
	Q_UNUSED(chn)
	Q_UNUSED(srate)
}
void QMPlay2Extensions::sendSoundData(const QByteArray &)
{}

QMPlay2Extensions::~QMPlay2Extensions()
{}

void QMPlay2Extensions::init()
{}
