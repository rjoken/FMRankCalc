#include "fmrankcalc.h"
#include <iostream>
#include <QSettings>

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
    UpdateTextboxes();
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

}

void FMRankCalc::WriteSettings() 
{
    QSettings settings("/keybinds.ini", QSettings::IniFormat);
    settings.beginGroup("Keybinds");
    settings.setValue("addFusions", QKeySequence(addFusionsKeybind).toString());
    settings.setValue("addEffectives", QKeySequence(addEffectivesKeybind).toString());
    settings.setValue("addFacedowns", QKeySequence(addFacedownsKeybind).toString());
    settings.setValue("addMagics", QKeySequence(addMagicsKeybind).toString());
    settings.setValue("addEquips", QKeySequence(addEquipsKeybind).toString());
    settings.setValue("addTraps", QKeySequence(addTrapsKeybind).toString());
    settings.setValue("addDefensives", QKeySequence(addDefensivesKeybind).toString());
    settings.setValue("addCards", QKeySequence(addCardsKeybind).toString());
    settings.setValue("addTurns", QKeySequence(addTurnsKeybind).toString());
    settings.setValue("minusFusions", QKeySequence(minusFusionsKeybind).toString());
    settings.setValue("minusEffectives", QKeySequence(minusEffectivesKeybind).toString());
    settings.setValue("minusFacedowns", QKeySequence(minusFacedownsKeybind).toString());
    settings.setValue("minusMagics", QKeySequence(minusMagicsKeybind).toString());
    settings.setValue("minusEquips", QKeySequence(minusEquipsKeybind).toString());
    settings.setValue("minusTraps", QKeySequence(minusTrapsKeybind).toString());
    settings.setValue("minusDefensives", QKeySequence(minusDefensivesKeybind).toString());
    settings.setValue("minusCards", QKeySequence(minusCardsKeybind).toString());
    settings.setValue("minusTurns", QKeySequence(minusTurnsKeybind).toString());
    settings.setValue("reset", QKeySequence(resetKeybind).toString());
}

void FMRankCalc::ReadSettings()
{
    QSettings settings("/keybinds.ini", QSettings::IniFormat);
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
    else return -2;
}

int FMRankCalc::UpdateDefensivePoints(int defensives)
{
    if (defensives <= 1) return 0;
    else return -10;
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
    else return -12;
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
    if (cards >= 37) return -7;
    else if (cards >= 32) return -5;
    else if (cards >= 13) return 0;
    else if (cards >= 32) return 12;
    else return 15;
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
