#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_fmrankcalc.h"
#include <qsettings.h>

class FMRankCalc : public QMainWindow
{
    Q_OBJECT

public:
    FMRankCalc(QWidget *parent = nullptr);
    ~FMRankCalc();
    void keyPressEvent(QKeyEvent* e);
    void Initialise();
    void WriteSettings();
    void DefaultKeybinds();
    void ReadSettings();
    void UpdateTextboxes();
    void btn_atecMode_Clicked();
    void btn_reset_Clicked();
    void btn_addFusions_Clicked();
    void btn_minusFusions_Clicked();
    void btn_addCards_Clicked();
    void btn_minusCards_Clicked();
    void btn_addFacedowns_Clicked();
    void btn_minusFacedowns_Clicked();
    void btn_addEffectives_Clicked();
    void btn_minusEffectives_Clicked();
    void btn_addEquips_Clicked();
    void btn_minusEquips_Clicked();
    void btn_addMagics_Clicked();
    void btn_minusMagics_Clicked();
    void btn_addTraps_Clicked();
    void btn_minusTraps_Clicked();
    void btn_addTurns_Clicked();
    void btn_minusTurns_Clicked();
    void btn_addDefensives_Clicked();
    void btn_minusDefensives_Clicked();
    void cbx_lifePoints_Changed();
    void check_alwaysOnTop_Changed();
    void check_globalHotkeys_Changed();
    void btn_add1Starchip_Clicked();
    void btn_add2Starchip_Clicked();
    void btn_add3Starchip_Clicked();
    void btn_add4Starchip_Clicked();
    void btn_add5Starchip_Clicked();
    void btn_removeStarchips_Clicked();
    int UpdateTurnPoints(int turns);
    int UpdateEffectivePoints(int effectives);
    int UpdateDefensivePoints(int defensives);
    int UpdateFacedownPoints(int facedowns);
    int UpdateFusionPoints(int fusions);
    int UpdateEquipPoints(int equips);
    int UpdateMagicPoints(int magics);
    int UpdateTrapPoints(int traps);
    int UpdateCardsPoints(int cards);
    int UpdateLPPoints(int lp);
    int UpdateTotalPoints();

    void btn_addFusionsHotkey_Clicked();
    void btn_addEffectivesHotkey_Clicked();
    void btn_addFacedownsHotkey_Clicked();
    void btn_addMagicsHotkey_Clicked();
    void btn_addEquipsHotkey_Clicked();
    void btn_addTrapsHotkey_Clicked();
    void btn_addDefensivesHotkey_Clicked();
    void btn_addCardsHotkey_Clicked();
    void btn_addTurnsHotkey_Clicked();
    void btn_minusFusionsHotkey_Clicked();
    void btn_minusEffectivesHotkey_Clicked();
    void btn_minusFacedownsHotkey_Clicked();
    void btn_minusMagicsHotkey_Clicked();
    void btn_minusEquipsHotkey_Clicked();
    void btn_minusTrapsHotkey_Clicked();
    void btn_minusDefensivesHotkey_Clicked();
    void btn_minusCardsHotkey_Clicked();
    void btn_minusTurnsHotkey_Clicked();
    void btn_add1StarchipHotkey_Clicked();
    void btn_add2StarchipHotkey_Clicked();
    void btn_add3StarchipHotkey_Clicked();
    void btn_add4StarchipHotkey_Clicked();
    void btn_add5StarchipHotkey_Clicked();
    void btn_resetHotkey_Clicked();

    void btn_saveKeybinds_Clicked();

    void RegisterGlobalHotkeys();
    void UnregisterGlobalHotkeys();

    QString GetRank(int points);



private:
    Ui::FMRankCalcClass ui;
    int turnPoints;
    int effectivePoints;
    int defensivePoints;
    int facedownPoints;
    int fusionPoints;
    int equipPoints;
    int magicPoints;
    int trapPoints;
    int cardsPoints;
    int lpPoints;
    int totalPoints;
    int victoryConditionPoints;
    int turns = 0;
    int effectives = 0;
    int defensives = 0;
    int facedowns = 0;
    int fusions = 0;
    int equips = 0;
    int magics = 0;
    int traps = 0;
    int cards = 0;
    int lp = 0;
    int starchips = 0;
    bool globalHotkeys = false;
    QSettings keybindSettings;
    Qt::Key addFusionsKeybind;
    Qt::Key addEffectivesKeybind;
    Qt::Key addFacedownsKeybind;
    Qt::Key addMagicsKeybind;
    Qt::Key addEquipsKeybind;
    Qt::Key addTrapsKeybind;
    Qt::Key addDefensivesKeybind;
    Qt::Key addCardsKeybind;
    Qt::Key addTurnsKeybind;
    Qt::Key minusFusionsKeybind;
    Qt::Key minusEffectivesKeybind;
    Qt::Key minusFacedownsKeybind;
    Qt::Key minusMagicsKeybind;
    Qt::Key minusEquipsKeybind;
    Qt::Key minusTrapsKeybind;
    Qt::Key minusDefensivesKeybind;
    Qt::Key minusCardsKeybind;
    Qt::Key minusTurnsKeybind;
    Qt::Key resetKeybind;
    Qt::Key add1Keybind;
    Qt::Key add2Keybind;
    Qt::Key add3Keybind;
    Qt::Key add4Keybind;
    Qt::Key add5Keybind;
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result);

};
