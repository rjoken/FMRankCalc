#include "fmrankcalc.h"
#ifdef _WIN32
    #include <Windows.h>
#endif
#include <iostream>
#include <QSettings>
#include <QKeyEvent>
#include <QMessageBox>


FMRankCalc::FMRankCalc(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    Initialise();
}

FMRankCalc::~FMRankCalc()
{

}

void FMRankCalc::Initialise() 
{

    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "hippochan", "FMRankCalc");
    if (settings.contains("Keybinds/reset"))
    {
        ReadSettings();
    }
    else
    {
        DefaultKeybinds();
    }
    UpdateTextboxes();

    //Lots of UI element event connections
    connect(ui.btn_addFusions, &QPushButton::released, this, &FMRankCalc::btn_addFusions_Clicked);
    connect(ui.btn_minusFusions, &QPushButton::released, this, &FMRankCalc::btn_minusFusions_Clicked);
    connect(ui.btn_addCards, &QPushButton::released, this, &FMRankCalc::btn_addCards_Clicked);
    connect(ui.btn_minusCards, &QPushButton::released, this, &FMRankCalc::btn_minusCards_Clicked);
    connect(ui.btn_addFacedowns, &QPushButton::released, this, &FMRankCalc::btn_addFacedowns_Clicked);
    connect(ui.btn_minusFacedowns, &QPushButton::released, this, &FMRankCalc::btn_minusFacedowns_Clicked);
    connect(ui.btn_addEffectives, &QPushButton::released, this, &FMRankCalc::btn_addEffectives_Clicked);
    connect(ui.btn_minusEffectives, &QPushButton::released, this, &FMRankCalc::btn_minusEffectives_Clicked);
    connect(ui.btn_addEquips, &QPushButton::released, this, &FMRankCalc::btn_addEquips_Clicked);
    connect(ui.btn_minusEquips, &QPushButton::released, this, &FMRankCalc::btn_minusEquips_Clicked);
    connect(ui.btn_addMagics, &QPushButton::released, this, &FMRankCalc::btn_addMagics_Clicked);
    connect(ui.btn_minusMagics, &QPushButton::released, this, &FMRankCalc::btn_minusMagics_Clicked);
    connect(ui.btn_addTraps, &QPushButton::released, this, &FMRankCalc::btn_addTraps_Clicked);
    connect(ui.btn_minusTraps, &QPushButton::released, this, &FMRankCalc::btn_minusTraps_Clicked);
    connect(ui.btn_addTurns, &QPushButton::released, this, &FMRankCalc::btn_addTurns_Clicked);
    connect(ui.btn_minusTurns, &QPushButton::released, this, &FMRankCalc::btn_minusTurns_Clicked);
    connect(ui.btn_addDefensives, &QPushButton::released, this, &FMRankCalc::btn_addDefensives_Clicked);
    connect(ui.btn_minusDefensives, &QPushButton::released, this, &FMRankCalc::btn_minusDefensives_Clicked);
    connect(ui.btn_atecMode, &QPushButton::released, this, &FMRankCalc::btn_atecMode_Clicked);
    connect(ui.cbx_lifePoints, &QComboBox::currentIndexChanged, this, &FMRankCalc::cbx_lifePoints_Changed);
    connect(ui.btn_reset, &QPushButton::released, this, &FMRankCalc::btn_reset_Clicked);
    connect(ui.check_alwaysOnTop, &QCheckBox::stateChanged, this, &FMRankCalc::check_alwaysOnTop_Changed);
    connect(ui.check_globalHotkeys, &QCheckBox::stateChanged, this, &FMRankCalc::check_globalHotkeys_Changed);
    connect(ui.btn_add1Starchip, &QPushButton::released, this, &FMRankCalc::btn_add1Starchip_Clicked);
    connect(ui.btn_add2Starchip, &QPushButton::released, this, &FMRankCalc::btn_add2Starchip_Clicked);
    connect(ui.btn_add3Starchip, &QPushButton::released, this, &FMRankCalc::btn_add3Starchip_Clicked);
    connect(ui.btn_add4Starchip, &QPushButton::released, this, &FMRankCalc::btn_add4Starchip_Clicked);
    connect(ui.btn_add5Starchip, &QPushButton::released, this, &FMRankCalc::btn_add5Starchip_Clicked);
    connect(ui.btn_removeStarchips, &QPushButton::released, this, &FMRankCalc::btn_removeStarchips_Clicked);
    connect(ui.tbx_removeStarchips, &QLineEdit::returnPressed, this, &FMRankCalc::tbx_removeStarchips_ReturnPressed);

    //Button connections for settings screen
    connect(ui.btn_addFusionsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addFusionsHotkey_Clicked);
    connect(ui.btn_addEffectivesHotkey, &QPushButton::released, this, &FMRankCalc::btn_addEffectivesHotkey_Clicked);
    connect(ui.btn_addFacedownsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addFacedownsHotkey_Clicked);
    connect(ui.btn_addMagicsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addMagicsHotkey_Clicked);
    connect(ui.btn_addEquipsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addEquipsHotkey_Clicked);
    connect(ui.btn_addTrapsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addTrapsHotkey_Clicked);
    connect(ui.btn_addDefensivesHotkey, &QPushButton::released, this, &FMRankCalc::btn_addDefensivesHotkey_Clicked);
    connect(ui.btn_addCardsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addCardsHotkey_Clicked);
    connect(ui.btn_addTurnsHotkey, &QPushButton::released, this, &FMRankCalc::btn_addTurnsHotkey_Clicked);
    connect(ui.btn_minusFusionsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusFusionsHotkey_Clicked);
    connect(ui.btn_minusEffectivesHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusEffectivesHotkey_Clicked);
    connect(ui.btn_minusFacedownsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusFacedownsHotkey_Clicked);
    connect(ui.btn_minusMagicsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusMagicsHotkey_Clicked);
    connect(ui.btn_minusEquipsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusEquipsHotkey_Clicked);
    connect(ui.btn_minusTrapsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusTrapsHotkey_Clicked);
    connect(ui.btn_minusDefensivesHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusDefensivesHotkey_Clicked);
    connect(ui.btn_minusCardsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusCardsHotkey_Clicked);
    connect(ui.btn_minusTurnsHotkey, &QPushButton::released, this, &FMRankCalc::btn_minusTurnsHotkey_Clicked);
    connect(ui.btn_add1StarchipHotkey, &QPushButton::released, this, &FMRankCalc::btn_add1StarchipHotkey_Clicked);
    connect(ui.btn_add2StarchipHotkey, &QPushButton::released, this, &FMRankCalc::btn_add2StarchipHotkey_Clicked);
    connect(ui.btn_add3StarchipHotkey, &QPushButton::released, this, &FMRankCalc::btn_add3StarchipHotkey_Clicked);
    connect(ui.btn_add4StarchipHotkey, &QPushButton::released, this, &FMRankCalc::btn_add4StarchipHotkey_Clicked);
    connect(ui.btn_add5StarchipHotkey, &QPushButton::released, this, &FMRankCalc::btn_add5StarchipHotkey_Clicked);
    connect(ui.btn_resetHotkey, &QPushButton::released, this, &FMRankCalc::btn_resetHotkey_Clicked);
    connect(ui.btn_saveKeybinds, &QPushButton::released, this, &FMRankCalc::btn_saveKeybinds_Clicked);
}

#ifdef _WIN32
//Native event handler for global hotkeys
bool FMRankCalc::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    Q_UNUSED(eventType);
    Q_UNUSED(result);
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY)
    {
        if (msg->wParam == 0)
        {
            btn_addFusions_Clicked();
            return true;
        }
        if (msg->wParam == 1)
        {
            btn_addEffectives_Clicked();
            return true;
        }
        if (msg->wParam == 2)
        {
            btn_addFacedowns_Clicked();
            return true;
        }
        if (msg->wParam == 3)
        {
            btn_addMagics_Clicked();
            return true;
        }
        if (msg->wParam == 4)
        {
            btn_addEquips_Clicked();
            return true;
        }
        if (msg->wParam == 5)
        {
            btn_addTraps_Clicked();
            return true;
        }
        if (msg->wParam == 6)
        {
            btn_addDefensives_Clicked();
            return true;
        }
        if (msg->wParam == 7)
        {
            btn_addCards_Clicked();
            return true;
        }
        if (msg->wParam == 8)
        {
            btn_addTurns_Clicked();
            return true;
        }
        if (msg->wParam == 9)
        {
            btn_minusFusions_Clicked();
            return true;
        }
        if (msg->wParam == 10)
        {
            btn_minusEffectives_Clicked();
            return true;
        }
        if (msg->wParam == 11)
        {
            btn_minusFacedowns_Clicked();
            return true;
        }
        if (msg->wParam == 12)
        {
            btn_minusMagics_Clicked();
            return true;
        }
        if (msg->wParam == 13)
        {
            btn_minusEquips_Clicked();
            return true;
        }
        if (msg->wParam == 14)
        {
            btn_minusTraps_Clicked();
            return true;
        }
        if (msg->wParam == 15)
        {
            btn_minusDefensives_Clicked();
            return true;
        }
        if (msg->wParam == 16)
        {
            btn_minusCards_Clicked();
            return true;
        }
        if (msg->wParam == 17)
        {
            btn_minusTurns_Clicked();
            return true;
        }
        if (msg->wParam == 18)
        {
            btn_add1Starchip_Clicked();
            return true;
        }
        if (msg->wParam == 19)
        {
            btn_add2Starchip_Clicked();
            return true;
        }
        if (msg->wParam == 20)
        {
            btn_add3Starchip_Clicked();
            return true;
        }
        if (msg->wParam == 21)
        {
            btn_add4Starchip_Clicked();
            return true;
        }
        if (msg->wParam == 22)
        {
            btn_add5Starchip_Clicked();
            return true;
        }
        if (msg->wParam == 23)
        {
            btn_reset_Clicked();
            return true;
        }
    }
    return false;
}

void FMRankCalc::RegisterGlobalHotkeys()
{
    if (!RegisterHotKey(HWND(winId()), 0, MOD_NOREPEAT, addFusionsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add fusion global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 1, MOD_NOREPEAT, addEffectivesKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add effectives global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 2, MOD_NOREPEAT, addFacedownsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add facedowns global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 3, MOD_NOREPEAT, addMagicsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add magics global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 4, MOD_NOREPEAT, addEquipsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add equips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 5, MOD_NOREPEAT, addTrapsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add traps global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 6, MOD_NOREPEAT, addDefensivesKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add defensives global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 7, MOD_NOREPEAT, addCardsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add cards global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 8, MOD_NOREPEAT, addTurnsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add turns global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 9, MOD_NOREPEAT, minusFusionsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus fusion global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 10, MOD_NOREPEAT, minusEffectivesKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus effectives global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 11, MOD_NOREPEAT, minusFacedownsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus facedowns global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 12, MOD_NOREPEAT, minusMagicsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus magics global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 13, MOD_NOREPEAT, minusEquipsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus equips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 14, MOD_NOREPEAT, minusTrapsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus traps global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 15, MOD_NOREPEAT, minusDefensivesKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus defensives global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 16, MOD_NOREPEAT, minusCardsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus cards global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 17, MOD_NOREPEAT, minusTurnsKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register minus turns global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 18, MOD_NOREPEAT, add1Keybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add 1 starchip global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 19, MOD_NOREPEAT, add2Keybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add 2 starchips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 20, MOD_NOREPEAT, add3Keybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add 3 starchips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 21, MOD_NOREPEAT, add4Keybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add 4 starchips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 22, MOD_NOREPEAT, add5Keybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add 5 starchips global hotkey.");
    }
    if (!RegisterHotKey(HWND(winId()), 23, MOD_NOREPEAT, resetKeybind))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not register add reset global hotkey.");
    }
}

void FMRankCalc::UnregisterGlobalHotkeys()
{
    if (!UnregisterHotKey(HWND(winId()), 0))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add fusion global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 1))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add effectives global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 2))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add facedowns global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 3))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add magics global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 4))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add equips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 5))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add traps global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 6))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add defensives global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 7))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add cards global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 8))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add turns global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 9))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus fusion global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 10))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus effectives global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 11))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus facedowns global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 12))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus magics global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 13))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus equips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 14))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus traps global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 15))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus defensives global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 16))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus cards global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 17))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister minus turns global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 18))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add 1 starchip global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 19))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add 2 starchips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 20))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add 3 starchips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 21))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add 4 starchips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 22))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add 5 starchips global hotkey.");
    }
    if (!UnregisterHotKey(HWND(winId()), 23))
    {
        QMessageBox::warning(this, "Global hotkey error", "Could not unregister add reset global hotkey.");
    }
}

void FMRankCalc::check_globalHotkeys_Changed()
{
    globalHotkeys = !globalHotkeys;
    if (globalHotkeys)
    {
        RegisterGlobalHotkeys();
    }
    else
    {
        UnregisterGlobalHotkeys();
    }
}
#endif

void FMRankCalc::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_Escape)
    {
        //Cancel setting hotkey. Also just generally refreshes textboxes. No one needs to know :)
        UpdateTextboxes();
        return;
    }
    //This is a messy way of doing things
    if (ui.btn_addFusionsHotkey->hasFocus())
    {
        addFusionsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addFusionsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addEffectivesHotkey->hasFocus())
    {
        addEffectivesKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addEffectivesHotkey->clearFocus();
        return;
    }
    if (ui.btn_addFacedownsHotkey->hasFocus())
    {
        addFacedownsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addFacedownsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addMagicsHotkey->hasFocus())
    {
        addMagicsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addMagicsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addEquipsHotkey->hasFocus())
    {
        addEquipsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addEquipsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addTrapsHotkey->hasFocus())
    {
        addTrapsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addTrapsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addDefensivesHotkey->hasFocus())
    {
        addDefensivesKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addDefensivesHotkey->clearFocus();
        return;
    }
    if (ui.btn_addCardsHotkey->hasFocus())
    {
        addCardsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addCardsHotkey->clearFocus();
        return;
    }
    if (ui.btn_addTurnsHotkey->hasFocus())
    {
        addTurnsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_addTurnsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusFusionsHotkey->hasFocus())
    {
        minusFusionsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusFusionsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusEffectivesHotkey->hasFocus())
    {
        minusEffectivesKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusEffectivesHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusFacedownsHotkey->hasFocus())
    {
        minusFacedownsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusFacedownsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusMagicsHotkey->hasFocus())
    {
        minusMagicsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusMagicsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusEquipsHotkey->hasFocus())
    {
        minusEquipsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusEquipsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusTrapsHotkey->hasFocus())
    {
        minusTrapsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusTrapsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusDefensivesHotkey->hasFocus())
    {
        minusDefensivesKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusDefensivesHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusCardsHotkey->hasFocus())
    {
        minusCardsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusCardsHotkey->clearFocus();
        return;
    }
    if (ui.btn_minusTurnsHotkey->hasFocus())
    {
        minusTurnsKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_minusTurnsHotkey->clearFocus();
        return;
    }
    if (ui.btn_add1StarchipHotkey->hasFocus())
    {
        add1Keybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_add1StarchipHotkey->clearFocus();
        return;
    }
    if (ui.btn_add2StarchipHotkey->hasFocus())
    {
        add2Keybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_add2StarchipHotkey->clearFocus();
        return;
    }
    if (ui.btn_add3StarchipHotkey->hasFocus())
    {
        add3Keybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_add3StarchipHotkey->clearFocus();
        return;
    }
    if (ui.btn_add4StarchipHotkey->hasFocus())
    {
        add4Keybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_add4StarchipHotkey->clearFocus();
        return;
    }
    if (ui.btn_add5StarchipHotkey->hasFocus())
    {
        add5Keybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_add5StarchipHotkey->clearFocus();
        return;
    }
    if (ui.btn_resetHotkey->hasFocus())
    {
        resetKeybind = Qt::Key(e->key());
        UpdateTextboxes();
        ui.btn_resetHotkey->clearFocus();
        return;
    }
    if (!globalHotkeys)
    {
        if (e->key() == addFusionsKeybind)
        {
            btn_addFusions_Clicked();
            return;
        }
        if (e->key() == addEffectivesKeybind)
        {
            btn_addEffectives_Clicked();
            return;
        }
        if (e->key() == addFacedownsKeybind)
        {
            btn_addFacedowns_Clicked();
            return;
        }
        if (e->key() == addMagicsKeybind)
        {
            btn_addMagics_Clicked();
            return;
        }
        if (e->key() == addEquipsKeybind)
        {
            btn_addEquips_Clicked();
            return;
        }
        if (e->key() == addTrapsKeybind)
        {
            btn_addTraps_Clicked();
            return;
        }
        if (e->key() == addDefensivesKeybind)
        {
            btn_addDefensives_Clicked();
            return;
        }
        if (e->key() == addCardsKeybind)
        {
            btn_addCards_Clicked();
            return;
        }
        if (e->key() == addTurnsKeybind)
        {
            btn_addTurns_Clicked();
            return;
        }
        if (e->key() == minusFusionsKeybind)
        {
            btn_minusFusions_Clicked();
            return;
        }
        if (e->key() == minusEffectivesKeybind)
        {
            btn_minusEffectives_Clicked();
            return;
        }
        if (e->key() == minusFacedownsKeybind)
        {
            btn_minusFacedowns_Clicked();
            return;
        }
        if (e->key() == minusMagicsKeybind)
        {
            btn_minusMagics_Clicked();
            return;
        }
        if (e->key() == minusEquipsKeybind)
        {
            btn_minusEquips_Clicked();
            return;
        }
        if (e->key() == minusTrapsKeybind)
        {
            btn_minusTraps_Clicked();
            return;
        }
        if (e->key() == minusDefensivesKeybind)
        {
            btn_minusDefensives_Clicked();
            return;
        }
        if (e->key() == minusCardsKeybind)
        {
            btn_minusCards_Clicked();
            return;
        }
        if (e->key() == minusTurnsKeybind)
        {
            btn_minusTurns_Clicked();
            return;
        }
        if (e->key() == resetKeybind)
        {
            btn_reset_Clicked();
            return;
        }
        if (e->key() == add1Keybind)
        {
            btn_add1Starchip_Clicked();
            return;
        }
        if (e->key() == add2Keybind)
        {
            btn_add2Starchip_Clicked();
            return;
        }
        if (e->key() == add3Keybind)
        {
            btn_add3Starchip_Clicked();
            return;
        }
        if (e->key() == add4Keybind)
        {
            btn_add4Starchip_Clicked();
            return;
        }
        if (e->key() == add5Keybind)
        {
            btn_add5Starchip_Clicked();
            return;
        }
    }
}

void FMRankCalc::DefaultKeybinds()
{
    addFusionsKeybind = Qt::Key_Q;
    addEffectivesKeybind = Qt::Key_W;
    addFacedownsKeybind = Qt::Key_E;
    addMagicsKeybind = Qt::Key_R;
    addEquipsKeybind = Qt::Key_T;
    addTrapsKeybind = Qt::Key_Y;
    addDefensivesKeybind = Qt::Key_U;
    addCardsKeybind = Qt::Key_I;
    addTurnsKeybind = Qt::Key_O;
    minusFusionsKeybind = Qt::Key_A;
    minusEffectivesKeybind = Qt::Key_S;
    minusFacedownsKeybind = Qt::Key_D;
    minusMagicsKeybind = Qt::Key_F;
    minusEquipsKeybind = Qt::Key_G;
    minusTrapsKeybind = Qt::Key_H;
    minusDefensivesKeybind = Qt::Key_J;
    minusCardsKeybind = Qt::Key_K;
    minusTurnsKeybind = Qt::Key_L;
    resetKeybind = Qt::Key_P;
    add1Keybind = Qt::Key_1;
    add2Keybind = Qt::Key_2;
    add3Keybind = Qt::Key_3;
    add4Keybind = Qt::Key_4;
    add5Keybind = Qt::Key_5;
}

void FMRankCalc::btn_addFusionsHotkey_Clicked()
{
    ui.btn_addFusionsHotkey->setText("...");
}
void FMRankCalc::btn_addEffectivesHotkey_Clicked()
{
    ui.btn_addEffectivesHotkey->setText("...");
}
void FMRankCalc::btn_addFacedownsHotkey_Clicked()
{
    ui.btn_addFacedownsHotkey->setText("...");
}
void FMRankCalc::btn_addMagicsHotkey_Clicked()
{
    ui.btn_addMagicsHotkey->setText("...");
}
void FMRankCalc::btn_addEquipsHotkey_Clicked()
{
    ui.btn_addEquipsHotkey->setText("...");
}
void FMRankCalc::btn_addTrapsHotkey_Clicked()
{
    ui.btn_addTrapsHotkey->setText("...");
}
void FMRankCalc::btn_addDefensivesHotkey_Clicked()
{
    ui.btn_addDefensivesHotkey->setText("...");
}
void FMRankCalc::btn_addCardsHotkey_Clicked()
{
    ui.btn_addCardsHotkey->setText("...");
}
void FMRankCalc::btn_addTurnsHotkey_Clicked()
{
    ui.btn_addTurnsHotkey->setText("...");
}
void FMRankCalc::btn_minusFusionsHotkey_Clicked()
{
    ui.btn_minusFusionsHotkey->setText("...");
}
void FMRankCalc::btn_minusEffectivesHotkey_Clicked()
{
    ui.btn_minusEffectivesHotkey->setText("...");
}
void FMRankCalc::btn_minusFacedownsHotkey_Clicked()
{
    ui.btn_minusFacedownsHotkey->setText("...");
}
void FMRankCalc::btn_minusMagicsHotkey_Clicked()
{
    ui.btn_minusMagicsHotkey->setText("...");
}
void FMRankCalc::btn_minusEquipsHotkey_Clicked()
{
    ui.btn_minusEquipsHotkey->setText("...");
}
void FMRankCalc::btn_minusTrapsHotkey_Clicked()
{
    ui.btn_minusTrapsHotkey->setText("...");
}
void FMRankCalc::btn_minusDefensivesHotkey_Clicked()
{
    ui.btn_minusDefensivesHotkey->setText("...");
}
void FMRankCalc::btn_minusCardsHotkey_Clicked()
{
    ui.btn_minusCardsHotkey->setText("...");
}
void FMRankCalc::btn_minusTurnsHotkey_Clicked()
{
    ui.btn_minusTurnsHotkey->setText("...");
}
void FMRankCalc::btn_add1StarchipHotkey_Clicked()
{
    ui.btn_add1StarchipHotkey->setText("...");
}
void FMRankCalc::btn_add2StarchipHotkey_Clicked()
{
    ui.btn_add2StarchipHotkey->setText("...");
}
void FMRankCalc::btn_add3StarchipHotkey_Clicked()
{
    ui.btn_add3StarchipHotkey->setText("...");
}
void FMRankCalc::btn_add4StarchipHotkey_Clicked()
{
    ui.btn_add4StarchipHotkey->setText("...");
}
void FMRankCalc::btn_add5StarchipHotkey_Clicked()
{
    ui.btn_add5StarchipHotkey->setText("...");
}
void FMRankCalc::btn_resetHotkey_Clicked()
{
    ui.btn_resetHotkey->setText("...");
}

void FMRankCalc::btn_saveKeybinds_Clicked()
{
    WriteSettings();
}

//ON WINDOWS THIS STUFF IS STORED IN AppData/Roaming
void FMRankCalc::WriteSettings() 
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "hippochan", "FMRankCalc");
    settings.beginGroup("Keybinds");
    settings.setValue("addFusions", addFusionsKeybind);
    settings.setValue("addEffectives", addEffectivesKeybind);
    settings.setValue("addFacedowns", addFacedownsKeybind);
    settings.setValue("addMagics", addMagicsKeybind);
    settings.setValue("addEquips", addEquipsKeybind);
    settings.setValue("addTraps", addTrapsKeybind);
    settings.setValue("addDefensives", addDefensivesKeybind);
    settings.setValue("addCards", addCardsKeybind);
    settings.setValue("addTurns", addTurnsKeybind);
    settings.setValue("minusFusions", minusFusionsKeybind);
    settings.setValue("minusEffectives", minusEffectivesKeybind);
    settings.setValue("minusFacedowns", minusFacedownsKeybind);
    settings.setValue("minusMagics", minusMagicsKeybind);
    settings.setValue("minusEquips", minusEquipsKeybind);
    settings.setValue("minusTraps", minusTrapsKeybind);
    settings.setValue("minusDefensives", minusDefensivesKeybind);
    settings.setValue("minusCards", minusCardsKeybind);
    settings.setValue("minusTurns", minusTurnsKeybind);
    settings.setValue("add1Starchip", add1Keybind);
    settings.setValue("add2Starchip", add2Keybind);
    settings.setValue("add3Starchip", add3Keybind);
    settings.setValue("add4Starchip", add4Keybind);
    settings.setValue("add5Starchip", add5Keybind);
    settings.setValue("reset", resetKeybind);
    settings.endGroup();
}

void FMRankCalc::ReadSettings()
{
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "hippochan", "FMRankCalc");
    settings.beginGroup("Keybinds");
    addFusionsKeybind = Qt::Key(settings.value("addFusions").toInt());
    addEffectivesKeybind = Qt::Key(settings.value("addEffectives").toInt());
    addFacedownsKeybind = Qt::Key(settings.value("addFacedowns").toInt());
    addMagicsKeybind = Qt::Key(settings.value("addMagics").toInt());
    addEquipsKeybind = Qt::Key(settings.value("addEquips").toInt());
    addTrapsKeybind = Qt::Key(settings.value("addTraps").toInt());
    addDefensivesKeybind = Qt::Key(settings.value("addDefensives").toInt());
    addCardsKeybind = Qt::Key(settings.value("addCards").toInt());
    addTurnsKeybind = Qt::Key(settings.value("addTurns").toInt());
    minusFusionsKeybind = Qt::Key(settings.value("minusFusions").toInt());
    minusEffectivesKeybind = Qt::Key(settings.value("minusEffectives").toInt());
    minusFacedownsKeybind = Qt::Key(settings.value("minusFacedowns").toInt());
    minusMagicsKeybind = Qt::Key(settings.value("minusMagics").toInt());
    minusEquipsKeybind = Qt::Key(settings.value("minusEquips").toInt());
    minusTrapsKeybind = Qt::Key(settings.value("minusTraps").toInt());
    minusDefensivesKeybind = Qt::Key(settings.value("minusDefensives").toInt());
    minusCardsKeybind = Qt::Key(settings.value("minusCards").toInt());
    minusTurnsKeybind = Qt::Key(settings.value("minusTurns").toInt());
    add1Keybind = Qt::Key(settings.value("add1Starchip").toInt());
    add2Keybind = Qt::Key(settings.value("add2Starchip").toInt());
    add3Keybind = Qt::Key(settings.value("add3Starchip").toInt());
    add4Keybind = Qt::Key(settings.value("add4Starchip").toInt());
    add5Keybind = Qt::Key(settings.value("add5Starchip").toInt());
    resetKeybind = Qt::Key(settings.value("reset").toInt());
    settings.endGroup();
}

void FMRankCalc::UpdateTextboxes()
{
    fusionPoints = UpdateFusionPoints(fusions);
    cardsPoints = UpdateCardsPoints(cards);
    facedownPoints = UpdateFacedownPoints(facedowns);
    effectivePoints = UpdateEffectivePoints(effectives);
    equipPoints = UpdateEquipPoints(equips);
    magicPoints = UpdateMagicPoints(magics);
    trapPoints = UpdateTrapPoints(traps);
    turnPoints = UpdateTurnPoints(turns);
    defensivePoints = UpdateDefensivePoints(defensives);
    lpPoints = UpdateLPPoints(lp);
    totalPoints = UpdateTotalPoints();

    ui.tbx_fusions->setText(QString::number(fusions));
    ui.tbx_cards->setText(QString::number(cards));
    ui.tbx_facedowns->setText(QString::number(facedowns));
    ui.tbx_effectives->setText(QString::number(effectives));
    ui.tbx_equips->setText(QString::number(equips));
    ui.tbx_magics->setText(QString::number(magics));
    ui.tbx_traps->setText(QString::number(traps));
    ui.tbx_turns->setText(QString::number(turns));
    ui.tbx_defensives->setText(QString::number(defensives));
    ui.tbx_currentRank->setText(QString::number(totalPoints) + " :: " + GetRank(totalPoints));
    ui.lbl_starchips->setText("Starchips: " + QString::number(starchips));

    ui.btn_addFusionsHotkey->setText(QKeySequence(addFusionsKeybind).toString());
    ui.btn_addEffectivesHotkey->setText(QKeySequence(addEffectivesKeybind).toString());
    ui.btn_addFacedownsHotkey->setText(QKeySequence(addFacedownsKeybind).toString());
    ui.btn_addMagicsHotkey->setText(QKeySequence(addMagicsKeybind).toString());
    ui.btn_addEquipsHotkey->setText(QKeySequence(addEquipsKeybind).toString());
    ui.btn_addTrapsHotkey->setText(QKeySequence(addTrapsKeybind).toString());
    ui.btn_addDefensivesHotkey->setText(QKeySequence(addDefensivesKeybind).toString());
    ui.btn_addCardsHotkey->setText(QKeySequence(addCardsKeybind).toString());
    ui.btn_addTurnsHotkey->setText(QKeySequence(addTurnsKeybind).toString());
    ui.btn_minusFusionsHotkey->setText(QKeySequence(minusFusionsKeybind).toString());
    ui.btn_minusEffectivesHotkey->setText(QKeySequence(minusEffectivesKeybind).toString());
    ui.btn_minusFacedownsHotkey->setText(QKeySequence(minusFacedownsKeybind).toString());
    ui.btn_minusMagicsHotkey->setText(QKeySequence(minusMagicsKeybind).toString());
    ui.btn_minusEquipsHotkey->setText(QKeySequence(minusEquipsKeybind).toString());
    ui.btn_minusTrapsHotkey->setText(QKeySequence(minusTrapsKeybind).toString());
    ui.btn_minusDefensivesHotkey->setText(QKeySequence(minusDefensivesKeybind).toString());
    ui.btn_minusCardsHotkey->setText(QKeySequence(minusCardsKeybind).toString());
    ui.btn_minusTurnsHotkey->setText(QKeySequence(minusTurnsKeybind).toString());
    ui.btn_add1StarchipHotkey->setText(QKeySequence(add1Keybind).toString());
    ui.btn_add2StarchipHotkey->setText(QKeySequence(add2Keybind).toString());
    ui.btn_add3StarchipHotkey->setText(QKeySequence(add3Keybind).toString());
    ui.btn_add4StarchipHotkey->setText(QKeySequence(add4Keybind).toString());
    ui.btn_add5StarchipHotkey->setText(QKeySequence(add5Keybind).toString());
    ui.btn_resetHotkey->setText(QKeySequence(resetKeybind).toString());

    ui.centralWidget->setFocus();
}

void FMRankCalc::btn_atecMode_Clicked()
{
    lp = 2;
    turns = 9;
    cards = 37;
    ui.cbx_lifePoints->setCurrentIndex(lp);
    ui.check_keepLifePoints->setCheckState(Qt::Checked);
    ui.check_keepTurns->setCheckState(Qt::Checked);
    ui.check_keepCards->setCheckState(Qt::Checked);
    UpdateTextboxes();
}

void FMRankCalc::btn_reset_Clicked() 
{
    if (ui.check_keepFusions->checkState() == 0) fusions = 0;
    if (ui.check_keepCards->checkState() == 0) cards = 0;
    if (ui.check_keepFacedowns->checkState() == 0) facedowns = 0;
    if (ui.check_keepEffectives->checkState() == 0) effectives = 0;
    if (ui.check_keepEquips->checkState() == 0) equips = 0;
    if (ui.check_keepMagics->checkState() == 0) magics = 0;
    if (ui.check_keepTraps->checkState() == 0) traps = 0;
    if (ui.check_keepTurns->checkState() == 0) turns = 0;
    if (ui.check_keepDefensives->checkState() == 0) defensives = 0;
    if (ui.check_keepLifePoints->checkState() == 0) {
        lp = 0;
        ui.cbx_lifePoints->setCurrentIndex(0);
    }
    UpdateTextboxes();

}

void FMRankCalc::btn_addFusions_Clicked()
{
    fusions += 1;
    fusionPoints = UpdateFusionPoints(fusions);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusFusions_Clicked()
{
    if(fusions > 0) fusions -= 1;    
    fusionPoints = UpdateFusionPoints(fusions);
    UpdateTextboxes();
}

void FMRankCalc::btn_addCards_Clicked()
{
    cards += 1;
    cardsPoints = UpdateCardsPoints(cards);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusCards_Clicked()
{
    if (cards > 0) cards -= 1;
    cardsPoints = UpdateCardsPoints(cards);
    UpdateTextboxes();
}

void FMRankCalc::btn_addFacedowns_Clicked()
{
    facedowns += 1;
    facedownPoints = UpdateFacedownPoints(facedowns);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusFacedowns_Clicked()
{
    if (facedowns > 0) facedowns -= 1;
    facedownPoints = UpdateFacedownPoints(facedowns);
    UpdateTextboxes();

}

void FMRankCalc::btn_addEffectives_Clicked()
{
    effectives += 1;
    effectivePoints = UpdateEffectivePoints(effectives);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusEffectives_Clicked()
{
    if (effectives > 0) effectives -= 1;
    effectivePoints = UpdateEffectivePoints(effectives);
    UpdateTextboxes();
}

void FMRankCalc::btn_addEquips_Clicked()
{
    equips += 1;
    equipPoints = UpdateEquipPoints(equips);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusEquips_Clicked()
{
    if (equips > 0) equips -= 1;
    equipPoints = UpdateEquipPoints(equips);
    UpdateTextboxes();
}

void FMRankCalc::btn_addMagics_Clicked()
{
    magics += 1;
    magicPoints = UpdateMagicPoints(magics);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusMagics_Clicked()
{
    if (magics > 0) magics -= 1;
    magicPoints = UpdateMagicPoints(magics);
    UpdateTextboxes();
}

void FMRankCalc::btn_addTraps_Clicked()
{
    traps += 1;
    trapPoints = UpdateTrapPoints(traps);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusTraps_Clicked()
{
    if (traps > 0) traps -= 1;
    trapPoints = UpdateTrapPoints(traps);
    UpdateTextboxes();
}

void FMRankCalc::btn_addTurns_Clicked()
{
    turns += 1;
    turnPoints = UpdateTurnPoints(turns);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusTurns_Clicked()
{
    if (turns > 0) turns -= 1;
    turnPoints = UpdateTurnPoints(turns);
    UpdateTextboxes();
}

void FMRankCalc::btn_addDefensives_Clicked()
{
    defensives += 1;
    defensivePoints = UpdateDefensivePoints(defensives);
    UpdateTextboxes();
}

void FMRankCalc::btn_minusDefensives_Clicked()
{
    if (defensives > 0) defensives -= 1;
    defensivePoints = UpdateDefensivePoints(defensives);
    UpdateTextboxes();
}

void FMRankCalc::cbx_lifePoints_Changed()
{
    lp = ui.cbx_lifePoints->currentIndex();
    lpPoints = UpdateLPPoints(lp);
    UpdateTextboxes();
}

void FMRankCalc::check_alwaysOnTop_Changed()
{
    setWindowFlags(windowFlags() ^ Qt::WindowStaysOnTopHint);
    this->show();
}

void FMRankCalc::btn_add1Starchip_Clicked()
{
    starchips += 1;
    UpdateTextboxes();
}
void FMRankCalc::btn_add2Starchip_Clicked()
{
    starchips += 2;
    UpdateTextboxes();
}
void FMRankCalc::btn_add3Starchip_Clicked()
{
    starchips += 3;
    UpdateTextboxes();
}
void FMRankCalc::btn_add4Starchip_Clicked()
{
    starchips += 4;
    UpdateTextboxes();
}
void FMRankCalc::btn_add5Starchip_Clicked()
{
    starchips += 5;
    UpdateTextboxes();
}

void FMRankCalc::tbx_removeStarchips_ReturnPressed()
{
    btn_removeStarchips_Clicked();
    ui.tbx_removeStarchips->clear();
    UpdateTextboxes();
}

void FMRankCalc::btn_removeStarchips_Clicked()
{
    int chipsToRemove = ui.tbx_removeStarchips->text().toInt();
    if (chipsToRemove <= starchips) 
    {
        starchips -= chipsToRemove;
    }
    ui.tbx_removeStarchips->clear();
    UpdateTextboxes();
}

int FMRankCalc::UpdateTurnPoints(int turns) 
{
    if (turns <= 4) return 12;
    else if (turns <= 8) return 8;
    else if (turns <= 28) return 0;
    else if (turns <= 32) return -8;
    else return -12;
}

int FMRankCalc::UpdateEffectivePoints(int effectives)
{
    if (effectives <= 1) return 4;
    else if (effectives <= 3) return 2;
    else if (effectives <= 9) return 0;
    else if (effectives <= 19) return -2;
    else return -4;
}

int FMRankCalc::UpdateDefensivePoints(int defensives)
{
    if (defensives <= 1) return 0;
    else if (defensives <= 5) return -10;
    else if (defensives <= 9) return -20;
    else if (defensives <= 14) return -30;
    else return -40;
}

int FMRankCalc::UpdateFacedownPoints(int facedowns)
{
    if (facedowns < 1) return 0;
    else if (facedowns <= 10) return -2;
    else if (facedowns <= 20) return -4;
    else if (facedowns <= 30) return -6;
    else return -8;
}

int FMRankCalc::UpdateFusionPoints(int fusions)
{
    if (fusions < 1) return 4;
    else if (fusions <= 4) return 0;
    else if (fusions <= 9) return -4;
    else if (fusions <= 14) return -8;
    else return -12;
}

int FMRankCalc::UpdateEquipPoints(int equips)
{
    if (equips < 1) return 4;
    else if (equips <= 4) return 0;
    else if (equips <= 9) return -4;
    else if (equips <= 14) return -8;
    else return -12;
}

int FMRankCalc::UpdateMagicPoints(int magics)
{
    if (magics < 1) return 2;
    else if (magics <= 3) return -4;
    else if (magics <= 6) return -8;
    else if (magics <= 9) return -12;
    else return -16;
}

int FMRankCalc::UpdateTrapPoints(int magics)
{
    if (traps < 1) return 2;
    else if (traps <= 2) return -8;
    else if (traps <= 4) return -16;
    else if (traps <= 6) return -24;
    else return -32;
}

int FMRankCalc::UpdateCardsPoints(int cards)
{
    if (cards <= 8) return 15;
    else if (cards <= 12) return 12;
    else if (cards <= 32) return 0;
    else if (cards <= 36) return -5;
    else return -7;
}

int FMRankCalc::UpdateLPPoints(int lp)
{
    /*
        Selected using combo box, so numbers don't match up. Using case statement.
        0 = 8000
        1 = 7000 - 7999
        2 = 1000 - 6999
        3 = 100 - 999
        4 = < 100
    */
    
    switch (lp)
    {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 0;
        case 3:
            return -5;
        case 4:
            return -7;
        default:
            return 6;
    }
    
}

int FMRankCalc::UpdateTotalPoints() 
{
    int selectedVictoryCondition = ui.cbx_victoryCondition->currentIndex();
    // Total Annihilation
    if (selectedVictoryCondition == 0) victoryConditionPoints = 2;
    // Win by Attrition
    else if (selectedVictoryCondition == 1) victoryConditionPoints = -40;
    // Win by Exodia
    else if (selectedVictoryCondition == 2) victoryConditionPoints = 40;
    return (50 + fusionPoints + cardsPoints + facedownPoints + effectivePoints + equipPoints + magicPoints + trapPoints + turnPoints + defensivePoints + lpPoints + victoryConditionPoints);
}

QString FMRankCalc::GetRank(int points)
{
    if (points <= 9) return "S-TEC";
    else if (points <= 19) return "A-TEC";
    else if (points <= 29) return "B-TEC";
    else if (points <= 39) return "C-TEC";
    else if (points <= 49) return "D-TEC";
    else if (points <= 59) return "D-POW";
    else if (points <= 69) return "C-POW";
    else if (points <= 79) return "B-POW";
    else if (points <= 89) return "A-POW";
    else return "S-POW";

}
