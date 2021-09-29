#include <iostream>
#include <vector>
#include "Record.h"
#ifndef MOST_STATE_VIOLATIONS_H
#define MOST_STATE_VIOLATIONS_H
                //State With the Most Violations
std::string mostViolationsState(std::vector<Record>& dataSet) {
    //I_N = IN
    int AL{ 0 }, AK{ 0 }, AZ{ 0 }, AR{ 0 }, CA{ 0 }, CO{ 0 }, CT{ 0 }, DE{ 0 },
        FL{ 0 }, GA{ 0 }, HI{ 0 }, ID{ 0 }, IL{ 0 }, I_N{ 0 }, IA{ 0 }, KS{ 0 },
        KY{ 0 }, LA{ 0 }, ME{ 0 }, MD{ 0 }, MA{ 0 }, MI{ 0 }, MN{ 0 }, MS{ 0 },
        MO{ 0 }, MT{ 0 }, NE{ 0 }, NV{ 0 }, NH{ 0 }, NJ{ 0 }, NM{ 0 }, NY{ 0 },
        NC{ 0 }, ND{ 0 }, OH{ 0 }, OK{ 0 }, OR{ 0 }, PA{ 0 }, RI{ 0 }, SC{ 0 },
        SD{ 0 }, TN{ 0 }, TX{ 0 }, UT{ 0 }, VT{ 0 }, VA{ 0 }, WA{ 0 }, WV{ 0 },
        WI{ 0 }, WY{ 0 }, DC{ 0 };
    int maxVotes{ 0 };
    std::vector<std::string> tempStates;
    std::string finalState;
    for (Record rec : dataSet) {
        tempStates.push_back(rec.getState());
    }
        //Count each state
    for (int i{ 0 }; i < tempStates.size(); i++) {
        if (tempStates[i] == "AL") { AL++; }
        else if (tempStates[i] == "AK") { AK++; }
        else if (tempStates[i] == "AZ") { AZ++; }
        else if (tempStates[i] == "AR") { AR++; }
        else if (tempStates[i] == "CA") { CA++; }
        else if (tempStates[i] == "CO") { CO++; }
        else if (tempStates[i] == "CT") { CT++; }
        else if (tempStates[i] == "DE") { DE++; }
        else if (tempStates[i] == "DC") { DC++; }
        else if (tempStates[i] == "FL") { FL++; }
        else if (tempStates[i] == "GA") { GA++; }
        else if (tempStates[i] == "HI") { HI++; }
        else if (tempStates[i] == "ID") { ID++; }
        else if (tempStates[i] == "IL") { IL++; }
        else if (tempStates[i] == "IN") { I_N++; }
        else if (tempStates[i] == "IA") { IA++; }
        else if (tempStates[i] == "KS") { KS++; }
        else if (tempStates[i] == "KY") { KY++; }
        else if (tempStates[i] == "LA") { LA++; }
        else if (tempStates[i] == "ME") { ME++; }
        else if (tempStates[i] == "MD") { MD++; }
        else if (tempStates[i] == "MA") { MA++; }
        else if (tempStates[i] == "MI") { MI++; }
        else if (tempStates[i] == "MN") { MN++; }
        else if (tempStates[i] == "MS") { MS++; }
        else if (tempStates[i] == "MO") { MO++; }
        else if (tempStates[i] == "MT") { MT++; }
        else if (tempStates[i] == "NE") { NE++; }
        else if (tempStates[i] == "NV") { NV++; }
        else if (tempStates[i] == "NH") { NH++; }
        else if (tempStates[i] == "NJ") { NJ++; }
        else if (tempStates[i] == "NM") { NM++; }
        else if (tempStates[i] == "NY") { NY++; }
        else if (tempStates[i] == "NC") { NC++; }
        else if (tempStates[i] == "ND") { ND++; }
        else if (tempStates[i] == "OH") { OH++; }
        else if (tempStates[i] == "OK") { OK++; }
        else if (tempStates[i] == "OR") { OR++; }
        else if (tempStates[i] == "PA") { PA++; }
        else if (tempStates[i] == "RI") { RI++; }
        else if (tempStates[i] == "SC") { SC++; }
        else if (tempStates[i] == "SD") { SD++; }
        else if (tempStates[i] == "TN") { TN++; }
        else if (tempStates[i] == "TX") { TX++; }
        else if (tempStates[i] == "UT") { UT++; }
        else if (tempStates[i] == "VT") { VT++; }
        else if (tempStates[i] == "VA") { VA++; }
        else if (tempStates[i] == "WA") { WA++; }
        else if (tempStates[i] == "WV") { WV++; }
        else if (tempStates[i] == "WI") { WI++; }
        else if (tempStates[i] == "WY") { WY++; }
        //cout << rec.getState() << endl;
    }
            //Find the state with most cases
    if (AL > maxVotes) {
        finalState = "Alabama";
        maxVotes = AL;
    }
    if (AK > maxVotes) {
        finalState = "Alaska";
        maxVotes = AK;
    }
    if (AZ > maxVotes) {
        finalState = "Arizona";
        maxVotes = AZ;
    }
    if (AR > maxVotes) {
        finalState = "Arkansas";
        maxVotes = AR;
    }
    if (CA > maxVotes) {
        finalState = "California";
        maxVotes = CA;
    }
    if (CO > maxVotes) {
        finalState = "Colorado";
        maxVotes = CO;
    }
    if (CT > maxVotes) {
        finalState = "Connecticut";
        maxVotes = CT;
    }
    if (DE > maxVotes) {
        finalState = "Delaware";
        maxVotes = DE;
    }
    if (DC > maxVotes) {
        finalState = "District of Columbia";
        maxVotes = DC;
    }
    if (FL > maxVotes) {
        finalState = "Florida";
        maxVotes = FL;
    }
    if (GA > maxVotes) {
        finalState = "Georgia";
        maxVotes = GA;
    }
    if (HI > maxVotes) {
        finalState = "Hawaii";
        maxVotes = HI;
    }
    if (ID > maxVotes) {
        finalState = "Idaho";
        maxVotes = ID;
    }
    if (IL > maxVotes) {
        finalState = "Illinois";
        maxVotes = IL;
    }
    if (I_N > maxVotes) {
        finalState = "Indiana";
        maxVotes = I_N;
    }
    if (IA > maxVotes) {
        finalState = "Iowa";
        maxVotes = IA;
    }
    if (KS > maxVotes) {
        finalState = "Kansas";
        maxVotes = KS;
    }
    if (KY > maxVotes) {
        finalState = "Kentucky";
        maxVotes = KY;
    }
    if (LA > maxVotes) {
        finalState = "Louisiana";
        maxVotes = LA;
    }
    if (ME > maxVotes) {
        finalState = "Maine";
        maxVotes = ME;
    }
    if (MD > maxVotes) {
        finalState = "Maryland";
        maxVotes = MD;
    }
    if (MA > maxVotes) {
        finalState = "Massachusetts";
        maxVotes = MA;
    }
    if (MI > maxVotes) {
        finalState = "Michigan";
        maxVotes = MI;
    }
    if (MN > maxVotes) {
        finalState = "Minnesota";
        maxVotes = MN;
    }
    if (MS > maxVotes) {
        finalState = "Mississippi";
        maxVotes = MS;
    }
    if (MO > maxVotes) {
        finalState = "Missouri";
        maxVotes = MO;
    }
    if (MT > maxVotes) {
        finalState = "Montana";
        maxVotes = MT;
    }
    if (NE > maxVotes) {
        finalState = "Nebraska";
        maxVotes = NE;
    }
    if (NV > maxVotes) {
        finalState = "Nevada";
        maxVotes = NV;
    }
    if (NH > maxVotes) {
        finalState = "New Hampshire";
        maxVotes = NH;
    }
    if (NJ > maxVotes) {
        finalState = "New Jersey";
        maxVotes = NJ;
    }
    if (NM > maxVotes) {
        finalState = "New Mexico";
        maxVotes = NM;
    }
    if (NY > maxVotes) {
        finalState = "New York";
        maxVotes = NY;
    }
    if (NC > maxVotes) {
        finalState = "North Carolina";
        maxVotes = NC;
    }
    if (ND > maxVotes) {
        finalState = "North Dakota";
        maxVotes = ND;
    }
    if (OH > maxVotes) {
        finalState = "Ohio";
        maxVotes = OH;
    }
    if (OK > maxVotes) {
        finalState = "Oklahoma";
        maxVotes = OK;
    }
    if (OR > maxVotes) {
        finalState = "Oregon";
        maxVotes = OR;
    }
    if (PA > maxVotes) {
        finalState = "Pennsylvania";
        maxVotes = PA;
    }
    if (RI > maxVotes) {
        finalState = "Rhode Island";
        maxVotes = RI;
    }
    if (SC > maxVotes) {
        finalState = "South Carolina";
        maxVotes = SC;
    }
    if (SD > maxVotes) {
        finalState = "South Dakota";
        maxVotes = SD;
    }
    if (TN > maxVotes) {
        finalState = "Tennessee";
        maxVotes = TN;
    }
    if (TX > maxVotes) {
        finalState = "Texas";
        maxVotes = TX;
    }
    if (UT > maxVotes) {
        finalState = "Utah";
        maxVotes = UT;
    }
    if (VT > maxVotes) {
        finalState = "Vermont";
        maxVotes = VT;
    }
    if (VA > maxVotes) {
        finalState = "Virginia";
        maxVotes = VA;
    }
    if (WA > maxVotes) {
        finalState = "Washington";
        maxVotes = WA;
    }
    if (WV > maxVotes) {
        finalState = "West Virginia";
        maxVotes = WV;
    }
    if (WI > maxVotes) {
        finalState = "Wisconsin";
        maxVotes = WI;
    }
    if (WY > maxVotes) {
        finalState = "Wyoming";
        maxVotes = WY;
    }
    return finalState;
} //end mostViolationsState()

#endif