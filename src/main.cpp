#include "miniaudio.h"
#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <unordered_map>
#include <conio.h>
#include <tuple>
#ifdef _WIN32
    #include <curses.h>
#else
    #include <ncurses.h>
#endif
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

std::unordered_map<std::string, int> breaks = {
    {"Think Break", 4},
    {"Alzir Break", 2},
    {"Angles Break", 1},
    {"Atlantis Amen", 1},
    {"Back Break", 2},
    {"Back Break 2", 2},
    {"Back Break 3", 2},
    {"Bad Break", 1},
    {"Beep Break", 4},
    {"Beta Break", 2},
    {"Blaze Break 2", 4},
    {"Blaze Break", 1},
    {"Blue Break", 2},
    {"Bonanza Break", 4},
    {"Boo Break", 2},
    {"Boo Worm Break", 4},
    {"Bouncer Break", 2},
    {"Box Break 2", 2},
    {"Box Break 3", 1},
    {"Box Break 4", 2},
    {"Box Break 5", 2},
    {"Box Break", 2},
    {"Breeze Break", 2},
    {"Bringing Me Break", 2},
    {"Bronx Break", 1},
    {"Brut Force Break", 1},
    {"Brut Force Fuller Break", 1},
    {"Bulldozer Amen 2", 2},
    {"Bulldozer Amen", 2},
    {"Calling Break", 2},
    {"Camo Break", 2},
    {"Calling Break", 2},
    {"Careless Break", 2},
    {"Centuries Break", 2},
    {"Champion Break", 1},
    {"Change Break", 1},
    {"Check Break", 2},
    {"Chopper Break", 2},
    {"Connected Break", 2},
    {"Control Amen 2", 2},
    {"Control Amen", 2},
    {"Control Break 2", 2},
    {"Control Break", 4},
    {"Control Kick Break", 2},
    {"Control Stutter Break", 4},
    {"Control Vocal Break", 2},
    {"Cool Amen", 2},
    {"Cool Break", 2},
    {"Cosmik Amen", 1},
    {"Cumulus Break", 1},
    {"Darkside Break", 2},
    {"Dayz Break", 1},
    {"Desire Break", 2},
    {"Detroit Break", 1},
    {"Detroit Percussion", 2},
    {"Difference Break 1", 1},
    {"Difference Break 2", 2},
    {"Disbatch Break 2", 2},
    {"Disbatch Break", 4},
    {"Effect Break 2", 1},
    {"Effect Break 3", 1},
    {"Effect Break", 4},
    {"Enchanted Break", 4},
    {"Essential Break", 2},
    {"Fairlight Break", 4},
    {"First Contact Amen", 2},
    {"Flutes Break", 1},
    {"Fountain Break", 4},
    {"Friday Break", 2},
    {"Futureproof Amen", 4},
    {"Games Amen", 2},
    {"Gene Break 2", 1},
    {"Gene Break", 1},
    {"Gene Chord Break", 1},
    {"Good Times Break", 2},
    {"Gravitational Break", 2},
    {"Guess Break", 4},
    {"Haze Break", 2},
    {"Haze Hybrid Break", 2},
    {"Heaven Break", 2},
    {"Heaven Carl Break", 2},
    {"Heli Break", 1},
    {"Horn Break", 2},
    {"Hurt U So Break", 2},
    {"Imagine Break", 4},
    {"Inner Break", 2},
    {"Jazz Note Break 2", 1},
    {"Jazz Note Break", 2},
    {"Jazz Thing Break", 4},
    {"Jazzy Break", 4},
    {"Killa Break", 2},
    {"Let It Roll Break", 2},
    {"Let There Break", 2},
    {"Let There Stutter Break", 1},
    {"Liberty Amen", 1},
    {"Lick Break", 2},
    {"Lights Break", 2},
    {"Limb Break", 2},
    {"Links Break", 2},
    {"Mach Break", 2},
    {"Machines Break", 2},
    {"Maintain Break", 1},
    {"London Break", 1},
    {"Marbles Break", 2},
    {"Massive Amen", 2},
    {"Massive Break", 2},
    {"Metropolis Break", 2},
    {"Moths Break", 4},
    {"Mutant Break", 2},
    {"My Sound Break 1", 2},
    {"My Sound Break 2", 2},
    {"My Sound Break 3", 2},
    {"Mystical Break", 2},
    {"Mystique Break", 2},
    {"Night Break", 2},
    {"Night Compound Break", 2},
    {"Oh Break", 2},
    {"Overcast Break", 1},
    {"Parallel World Break", 2},
    {"Peace Sign Break", 2},
    {"Pesh Break", 4},
    {"Physical Break 2", 2},
    {"Pin Up Break", 1},
    {"Piper Break", 1},
    {"Place Break", 2},
    {"Playboy Break", 4},
    {"Possible Worlds Break", 2},
    {"Pressin Break", 2},
    {"Prog Amen", 4},
    {"Prog Break", 4},
    {"Quest Break", 1},
    {"Rainfall Lite Break", 1},
    {"Reach Break", 1},
    {"Reckon Break", 1},
    {"Reel Funk Amen", 2},
    {"Reflections Break", 2},
    {"Repetoire Break", 4},
    {"Resolution Break", 2},
    {"Ricochet Break", 2},
    {"Right Break", 2},
    {"Rise Amen", 4},
    {"Rock Amen 2", 2},
    {"Rock On Roll 3", 2},
    {"Searchin Break 2", 2},
    {"Searchin Break 3", 2},
    {"Searchin Break", 4},
    {"Seatown Break", 4},
    {"Shock Break", 2},
    {"Shock Filter Break", 4},
    {"Shoes Break", 4},
    {"Sight Break", 2},
    {"Sonic Amen", 1},
    {"Sonic Break 2", 2},
    {"Sonic Break", 2},
    {"Sound Control Break", 4},
    {"Sound Murderer Break", 4},
    {"Sovreign Break", 2},
    {"Stepper Amen", 2},
    {"Stepper Break", 2},
    {"Still Break", 1},
    {"Stone Break", 2},
    {"Sunset Break", 2},
    {"Take You Break", 2},
    {"Tear Apache", 2},
    {"Tear Break", 2},
    {"Ten Break 2", 2},
    {"Terrain Break 2", 2},
    {"Terrain Break", 2},
    {"Terrorist Amen", 2},
    {"Trippin Break 2", 2},
    {"Trippin Break", 2},
    {"Tronik Break", 1},
    {"True Break", 2},
    {"Vapour Break", 2},
    {"Voyage Break", 2},
    {"Walk Break", 2},
    {"War Break", 2},
    {"Warhead Break 2", 2},
    {"Warhead Break", 2},
    {"Warned Break", 2},
    {"Warning Compound", 2},
    {"WarPeace Break", 2},
    {"Way Break", 2},
    {"Wheel Up Amen", 2},
    {"Worries Break", 1},
    {"Your Amen 2", 2},
    {"Your Amen", 2},
    {"Zone Break", 2},
    };
int dotRemap4[11] = {0,1,4,5,6,8,9,10,12,13,14};
int dotRemap2[4] = {0,1,4,5};


double pitches[4][32] = {
    {
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0
    },
    {
        1.0000000000, 1.0000000000, 1.0000000000, 1.0000000000,
        1.1224620483, 1.1224620483, 1.1224620483, 1.1224620483,
        0.8908987181, 0.8908987181, 0.8908987181, 0.8908987181,
        0.8908987181, 0.8908987181, 0.8908987181, 0.8908987181,
        1.0000000000, 1.0000000000, 1.0000000000, 1.0000000000,
        1.1224620483, 1.1224620483, 1.1224620483, 1.1224620483,
        0.8908987181, 0.8908987181, 0.8908987181, 0.8908987181,
        0.8908987181, 0.8908987181, 0.8908987181, 0.8908987181
    },
    {
        0.7491535384, 0.7491535384, 0.7491535384, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.1224620483, 1.1224620483, 1.1224620483,
        0.7491535384, 0.7491535384, 0.7491535384, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.1224620483, 1.1224620483, 1.1224620483
    },
    {
        1.4142135624, 1.4142135624, 1.4142135624, 1.4142135624,
        1.4983070769,
        1.1224620483, 1.1224620483, 1.1224620483,
        0.7491535384,
        1.0000000000, 1.0000000000, 1.0000000000,
        0.5946035575,
        0.7937005260, 0.7937005260, 0.7937005260,
        0.5297315472,
        0.7071067812, 0.7071067812, 0.7071067812,
        1.0000000000,
        0.7491535384, 0.7491535384, 0.7491535384,
        0.9438743127,
        0.6299605249, 0.6299605249, 0.6299605249,
        0.4204482076,
        0.5612310242, 0.5612310242, 0.5612310242
    }
    
    
};

int soundInit(ma_engine &engine, ma_sound &breakz, const std::string &breakName, ma_sound &pad, const std::string &padName, bool rideOn, ma_sound &ride) {
    ma_result result;
    result = ma_sound_init_from_file(&engine, ("../breaks/" + breakName + ".wav").c_str(), 0, NULL, NULL, &breakz);
    if (result != MA_SUCCESS) {
        std::cerr << "I couldn't load da break! \n";
        return int(result);
    }
    if (padName != "NONE") {
        result = ma_sound_init_from_file(&engine, ("../pads/" + padName + ".wav").c_str(), 0, NULL, NULL, &pad);
        if (result != MA_SUCCESS) {
            std::cerr << "I couldn't load da pad! \n";
            return int(result);
        }
    }
    if (rideOn) {
        result = ma_sound_init_from_file(&engine, "../breaks/Jazz_Ride.wav", 0, NULL, NULL, &ride);
        if (result != MA_SUCCESS) {
            std::cerr << "I couldn't load da ride! \n";
            return int(result);
        }
    }
    return 0;
}

std::tuple<int,int,int> decode(unsigned char c, int breakBars) {
    int index;
    int noteVal;
    int pitch;
    if (c == ' ') {
            index = 0xFF;
            noteVal = 0x0;
            pitch = 0;
        } else {
            if (breakBars == 4) {
                index = int(c) & 0x1F;
                noteVal = (int(c) & 0x60) >> 5;
                pitch = (int(c) & 0x80) >> 7;
                if (noteVal == 0x1) {index = dotRemap4[index%11];}
                }
            else if (breakBars == 2) {
                index = int(c) & 0xF;
                noteVal = (int(c) & 0x30) >> 4;
                pitch = ((int(c) & 0x40) == 0) ? 1 : 0;
                if (noteVal == 0x1) {index = dotRemap2[index%4];}
                }
            else if (breakBars == 1) {
                index = int(c) & 0x7;
                noteVal = (int(c) & 0x18) >> 3;
                pitch = ((int(c) & 0x20) == 0) ? 1 : 0;
                if (noteVal == 0x1) {index = index%2;}
                }
            }
    return std::make_tuple(index, noteVal, pitch);
}

int demoSound(ma_engine& engine, const std::string& path, float volume)
{
    ma_sound sound{};
    ma_result result = ma_sound_init_from_file(&engine, path.c_str(), 0, NULL, NULL, &sound);
    if (result != MA_SUCCESS) {
        std::cerr << "I couldn't load da demo sound! \n";
        return int(result);
    }

    ma_sound_set_volume(&sound, volume);

    ma_uint64 lengthFrames = 0;
    ma_sound_get_length_in_pcm_frames(&sound, &lengthFrames);

    ma_uint32 sampleRate = ma_engine_get_sample_rate(&engine);
    double seconds = 0.0;
    if (sampleRate > 0) {
        seconds = double(lengthFrames) / double(sampleRate);
    }
    if (seconds <= 0.0) {
        seconds = 2.0;
    }

    ma_sound_start(&sound);

    nodelay(stdscr, TRUE);

    auto start = std::chrono::steady_clock::now();
    bool done  = false;

    while (!done) {
        int ch = getch();
        if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) {
            done = true;
        }

        auto now = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(now - start).count();
        if (elapsed >= seconds) {
            done = true;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    nodelay(stdscr, FALSE);

    ma_sound_stop(&sound);
    ma_sound_uninit(&sound);
    return 0;
}



int main()
{
    // --------- MINIAUDIO / GLOBAL STATE ---------- //
    bool playback_running;
    int result;
    ma_engine engine;
    ma_sound breakz;
    ma_sound pad;
    ma_sound ride;

    bool rideOn = true;
    bool padOn  = true;

    ma_uint64 drums_length = 0;
    ma_uint64 pad_length   = 0;
    ma_uint32 sampleRate   = 48000;

    double pad_pitch   = 1.0;
    double tempo       = 180.0;
    int    patternSelect = 0;
    double masterVol   = 1.0;

    bool main_running  = true;

    std::string padName   = "Bulldozer Pad";
    std::string breakName = "Think Break";

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        std::cerr << "I couldn't load da engine! \n";
        return int(result);
    }

    // --------- CURSES INIT ---------- // 
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();

    int termRows, termCols;
    getmaxyx(stdscr, termRows, termCols);

    float relH = 0.4f;
    float relW = 0.6f;

    int boxH = static_cast<int>(termRows * relH);
    int boxW = static_cast<int>(termCols * relW);

    if (boxH < 8)  boxH = 8;   // enough rows for params + borders
    if (boxW < 30) boxW = 30;  // minimum width

    if (boxH > termRows) boxH = termRows;
    if (boxW > termCols) boxW = termCols;

    int startY = (termRows - boxH) / 2;
    int startX = (termCols - boxW) / 2;

    WINDOW* win = newwin(boxH, boxW, startY, startX);
    if (!win) {
        endwin();
        ma_engine_uninit(&engine);
        return 1;
    }

    // sequence window under the param box
    int seqWinY = startY + boxH + 1;
    int seqWinH = 3;
    if (seqWinY + seqWinH > termRows) {
        seqWinY = termRows - seqWinH;   // clamp to screen
        if (seqWinY < 0) seqWinY = 0;
    }

    WINDOW* seqWin = newwin(seqWinH, termCols, seqWinY, 0);
    if (!seqWin) {
        delwin(win);
        endwin();
        ma_engine_uninit(&engine);
        return 1;
    }

    keypad(win, TRUE);
    keypad(seqWin, TRUE);
    nodelay(stdscr, FALSE);

    auto recomputeLayout = [&]() {
        getmaxyx(stdscr, termRows, termCols);

        float relH = 0.4f;
        float relW = 0.6f;

        boxH = static_cast<int>(termRows * relH);
        boxW = static_cast<int>(termCols * relW);

        if (boxH < 8)  boxH = 8;
        if (boxW < 30) boxW = 30;
        if (boxH > termRows) boxH = termRows;
        if (boxW > termCols) boxW = termCols;

        startY = (termRows - boxH) / 2;
        startX = (termCols - boxW) / 2;

        seqWinH = 3;
        seqWinY = startY + boxH + 1;
        if (seqWinY + seqWinH > termRows) {
            seqWinY = termRows - seqWinH;
            if (seqWinY < 0) seqWinY = 0;
        }
    };

    // --------- PARAM STORAGE ---------- //  

    // Collect and sort break names once
    std::vector<std::string> breakNames;
    breakNames.reserve(breaks.size());
    for (auto &kv : breaks) {
        breakNames.push_back(kv.first);
    }
    std::sort(breakNames.begin(), breakNames.end());

    // Find index for initial breakName
    int breakIndex = 0;
    for (int i = 0; i < (int)breakNames.size(); ++i) {
        if (breakNames[i] == breakName) {
            breakIndex = i;
            break;
        }
    }

    std::vector<std::string> padNames = {
        "19 Pad", "31 Secs Pad", "360 Pad", "Apollo VCF Pad", "Apollo",
        "Aura Arp Pad", "Back Pad", "Bang Pad", "Boo Pad", "Bringing Me Pad",
        "Bulldozer Pad", "Careless Pad", "Connected Modu Pad", "Connected Pad",
        "Dred Pad", "Drumz BassPad", "Emotion Pad", "Enchanted Pad",
        "Face Pads", "Feenin Pad", "Fight Pad", "Fluid Pad", "Freedom Pad",
        "Global Kids Pad", "God Chord Pad", "Gravitational Pad",
        "Greetings Pad", "Grey Pad", "Groove Therapy Lo Pad",
        "Groove Therapy Pad", "High Point Pad", "Hoovers Pad", "Horn Pad",
        "I Spy Pad", "Inna Pad 2", "Inna Pad", "Inner Pad", "LED Pad",
        "Love Pad", "Maintain Pad", "Metropolis Pad", "Moomin Loop Pad",
        "Myriad Pad", "Night Train Pad", "Night Train Short Pad",
        "Northern Breakdown Pad", "Origin Pad", "Pesh Pad", "Physical Pad",
        "Portraits Pad", "Possible Worlds Pad", "Recharge Pad",
        "Reflections Pad", "Revelation Pad", "Rock Pad", "Roll Pad",
        "Seatown Pad", "Shoes Pad", "Sign Pad", "Sonic Pad 2", "Sonic Pad",
        "Spring Pad", "Stoned Pad", "Sweet Pad", "Take You Pad", "Tear Pad",
        "Ten Pad", "Terrain Pad", "Touch Vocal Pad", "Traenon Pad",
        "Travelling Pad", "True Pad", "Wash Pad", "What Ya Gonna Pad",
        "Your Pad"
    };
    int padIndex = 0;

    // Other params
    int   padPitchSemis = 0;
    int   padPattern    = patternSelect;
    bool  rideEnabled   = rideOn;
    bool  padEnabled    = padOn;

    // MASTER VOLUME UI state: 0–200% mapped to masterVol
    int masterVolPercent = (int)std::round(masterVol * 100.0);
    if (masterVolPercent < 0)   masterVolPercent = 0;
    if (masterVolPercent > 100) masterVolPercent = 100;
    masterVol = masterVolPercent / 100.0;

    // Param selection
    enum Param {
        P_TEMPO = 0,
        P_MASTER,
        P_BREAK,
        P_RIDE,
        P_PAD,
        P_PAD_PITCH,
        P_PAD_PATTERN,
        P_COUNT
    };
    int selectedParam = P_TEMPO;

    // Focus between param box and sequence box
    enum Focus {
        F_PARAMS,
        F_SEQ
    };
    Focus focus = F_PARAMS;
    bool firstUI = true;

    std::string seq;
    bool playing       = false;   // playback state
    bool startPlayback = false;   // set when Enter pressed on SEQ with text

    // --------- DRAW HELPERS ---------- //

    auto drawUI = [&]() {
        werase(win);
        box(win, 0, 0);

        const char* title = (focus == F_PARAMS) ? "I <3 JUNGLE" : "I <3 JUNGLE";
        int titleX = (boxW - (int)std::strlen(title)) / 2;
        if (titleX < 1) titleX = 1;
        mvwprintw(win, 0, titleX, "%s", title);

        int leftCol  = 2;
        int firstRow = 2;
        int row      = firstRow;

        auto drawRow = [&](int param, const char* label, const std::string& value) {
            bool sel = (param == selectedParam && focus == F_PARAMS);
            if (sel) wattron(win, A_REVERSE);

            mvwprintw(win, row, leftCol, "%s", label);

            int valueCol = boxW - 2 - (int)value.size();
            if (valueCol <= leftCol + 1) valueCol = leftCol + 1;
            mvwprintw(win, row, valueCol, "%s", value.c_str());

            if (sel) wattroff(win, A_REVERSE);
            ++row;
        };

        // values
        char tempoBuf[32];
        std::snprintf(tempoBuf, sizeof(tempoBuf), "%.1f", tempo);
        std::string tempoVal = tempoBuf;

        char masterBuf[32];
        std::snprintf(masterBuf, sizeof(masterBuf), "%d%%", masterVolPercent);
        std::string masterVal = masterBuf;

        std::string breakVal = breakNames.empty() ? std::string("NONE") : breakNames[breakIndex];
        std::string rideVal  = rideEnabled ? "ENABLED" : "DISABLED";
        std::string padVal   = padEnabled
                                ? (padNames.empty() ? std::string("NONE")
                                                    : padNames[padIndex])
                                : "DISABLED";

        char pitchBuf[32];
        if (padPitchSemis > 0)
            std::snprintf(pitchBuf, sizeof(pitchBuf), "+%d st", padPitchSemis);
        else
            std::snprintf(pitchBuf, sizeof(pitchBuf), "%d st", padPitchSemis);
        std::string pitchVal = pitchBuf;

        char patternBuf[16];
        std::snprintf(patternBuf, sizeof(patternBuf), "%d", padPattern);
        std::string patternVal = patternBuf;

        // rows
        row = firstRow;
        drawRow(P_TEMPO,      "TEMPO",       tempoVal);
        drawRow(P_MASTER,     "MASTER VOL",  masterVal);
        drawRow(P_BREAK,      "BREAK",       breakVal);
        drawRow(P_RIDE,       "RIDE",        rideVal);
        drawRow(P_PAD,        "PAD",         padVal);
        drawRow(P_PAD_PITCH,  "PAD PITCH",   pitchVal);
        drawRow(P_PAD_PATTERN,"PAD PATTERN", patternVal);

        mvwprintw(win, boxH - 2, 2, "[TAB] SWITCH MENU  [ESC] QUIT  [ENTER]: PLAY / PAUSE");

        wrefresh(win);
    };

    auto drawSeqUI = [&]() {
        werase(seqWin);
        box(seqWin, 0, 0);

        const char* title = (focus == F_SEQ) ? "SEQUENCE" : "SEQUENCE";
        mvwprintw(seqWin, 0, 2, "%s", title);

        std::string label = "SEQ: ";
        mvwprintw(seqWin, 1, 2, "%s", label.c_str());

        int maxLen = termCols - 4 - (int)label.size();
        std::string toShow = seq;
        if ((int)toShow.size() > maxLen) {
            toShow = toShow.substr(toShow.size() - maxLen);
        }

        mvwprintw(seqWin, 1, 2 + (int)label.size(), "%s", toShow.c_str());

        if (!playing && focus == F_SEQ) {
            int caretX = 2 + (int)label.size() + (int)toShow.size();
            if (caretX < termCols - 2) {
                mvwaddch(seqWin, 1, caretX, '_');
            }
        }

        wrefresh(seqWin);
    };

    auto drawSeqPlayback = [&](int currentIndex) {
        werase(seqWin);
        box(seqWin, 0, 0);

        const char* title = "SEQUENCE (PLAYING)";
        mvwprintw(seqWin, 0, 2, "%s", title);

        std::string label = "SEQ: ";
        mvwprintw(seqWin, 1, 2, "%s", label.c_str());

        int maxLen = termCols - 4 - (int)label.size();
        std::string toShow = seq;
        int offset = 0;
        if ((int)toShow.size() > maxLen) {
            offset = (int)toShow.size() - maxLen;
            toShow = toShow.substr(offset);
        }

        for (int i = 0; i < (int)toShow.size(); ++i) {
            int seqIndex = offset + i;
            if (seqIndex == currentIndex) wattron(seqWin, A_REVERSE);
            mvwaddch(seqWin, 1, 2 + (int)label.size() + i, toShow[i]);
            if (seqIndex == currentIndex) wattroff(seqWin, A_REVERSE);
        }

        wrefresh(seqWin);
    };

    using clock = std::chrono::steady_clock;

    // --------- MAIN LOOP ---------- //
    while (main_running) {
        // ---- UI PHASE ---- //
        startPlayback = false;
        playing       = false;
        if (firstUI) {
            focus   = F_PARAMS;
            firstUI = false;
        }

        drawUI();
        drawSeqUI();

        while (main_running && !startPlayback) {
            int ch;
            if (focus == F_PARAMS) {
                ch = wgetch(win);
            } else {
                ch = wgetch(seqWin);
            }

            // ESC quits everything
            if (ch == 27) { // ESC
                main_running = false;
                break;
            }

            if (ch == KEY_RESIZE) {
                // For PDCurses, this makes it recalc LINES/COLS:
                // (ncurses handles it automatically after KEY_RESIZE)
                #ifdef PDCURSES
                    resize_term(0, 0);
                #endif

                recomputeLayout();

                // Resize + move windows to the new positions
                wresize(win,   boxH, boxW);
                mvwin(win,     startY, startX);

                wresize(seqWin, seqWinH, termCols);
                mvwin(seqWin,   seqWinY, 0);

                // Clear & redraw everything
                erase();
                refresh();
                drawUI();
                drawSeqUI();
                continue;
            }


            // TAB toggles focus between params and sequence box
            if (ch == '\t') {
                focus = (focus == F_PARAMS) ? F_SEQ : F_PARAMS;
                drawUI();
                drawSeqUI();
                continue;
            }

            if (focus == F_PARAMS) {
                // --- PARAMETER MODE --- //

                if (ch == '\n' || ch == KEY_ENTER || ch == '\r') {
                    if (selectedParam == P_BREAK) {
                        std::string path = "../breaks/" + breakName + ".wav";
                        demoSound(engine, path, float(masterVol));          // use master volume
                    } else if (selectedParam == P_PAD) {
                        if (padEnabled) {
                            std::string path = "../pads/" + padName + ".wav";
                            demoSound(engine, path, float(0.5 * masterVol)); // pad preview a bit lower
                        }
                    }
                    drawUI();
                    drawSeqUI();
                    continue;
                }

                switch (ch) {
                case KEY_UP:
                case '8':
                    selectedParam = (selectedParam - 1 + P_COUNT) % P_COUNT;
                    break;

                case KEY_DOWN:
                case '2':
                    selectedParam = (selectedParam + 1) % P_COUNT;
                    break;

                case KEY_LEFT:
                case '4': {
                    int dir = -1;
                    switch (selectedParam) {
                        case P_TEMPO:
                            tempo += dir * 1.0;
                            if (tempo < 60.0)  tempo = 60.0;
                            if (tempo > 200.0) tempo = 200.0;
                            break;
                        case P_MASTER:
                            masterVolPercent += dir * 5;
                            if (masterVolPercent < 0)   masterVolPercent = 0;
                            if (masterVolPercent > 200) masterVolPercent = 200;
                            masterVol = masterVolPercent / 100.0;
                            break;
                        case P_BREAK:
                            if (!breakNames.empty()) {
                                int n = (int)breakNames.size();
                                breakIndex = (breakIndex + dir + n) % n;
                                breakName  = breakNames[breakIndex];
                            }
                            break;
                        case P_RIDE:
                            rideEnabled = !rideEnabled;
                            break;
                        case P_PAD:
                            if (!padNames.empty()) {
                                int n = (int)padNames.size();
                                padIndex = (padIndex + dir + n) % n;
                                padEnabled = true;
                                padName = padNames[padIndex];
                            }
                            break;
                        case P_PAD_PITCH:
                            padPitchSemis += dir;
                            if (padPitchSemis < -24) padPitchSemis = -24;
                            break;
                        case P_PAD_PATTERN:
                            padPattern = (padPattern + dir + 4) % 4;
                            patternSelect = padPattern;
                            break;
                    }
                    break;
                }

                case KEY_RIGHT:
                case '6': {
                    int dir = +1;
                    switch (selectedParam) {
                        case P_TEMPO:
                            tempo += dir * 1.0;
                            if (tempo < 60.0)  tempo = 60.0;
                            if (tempo > 200.0) tempo = 200.0;
                            break;
                        case P_MASTER:
                            masterVolPercent += dir * 5;
                            if (masterVolPercent < 0)   masterVolPercent = 0;
                            if (masterVolPercent > 200) masterVolPercent = 200;
                            masterVol = masterVolPercent / 100.0;
                            break;
                        case P_BREAK:
                            if (!breakNames.empty()) {
                                int n = (int)breakNames.size();
                                breakIndex = (breakIndex + dir + n) % n;
                                breakName  = breakNames[breakIndex];
                            }
                            break;
                        case P_RIDE:
                            rideEnabled = !rideEnabled;
                            break;
                        case P_PAD:
                            if (!padNames.empty()) {
                                int n = (int)padNames.size();
                                padIndex = (padIndex + dir + n) % n;
                                padEnabled = true;
                                padName = padNames[padIndex];
                            }
                            break;
                        case P_PAD_PITCH:
                            padPitchSemis += dir;
                            if (padPitchSemis > 24) padPitchSemis = 24;
                            break;
                        case P_PAD_PATTERN:
                            padPattern = (padPattern + dir + 4) % 4;
                            patternSelect = padPattern;
                            break;
                    }
                    break;
                }

                case 'd':
                case 'D':
                    if (selectedParam == P_RIDE) {
                        rideEnabled = !rideEnabled;
                    } else if (selectedParam == P_PAD) {
                        padEnabled = !padEnabled;
                    }
                    break;

                default:
                    break;
                }

            } else {
                // --- SEQUENCE TEXT MODE --- //

                if (ch == '\n' || ch == KEY_ENTER || ch == '\r') {
                    if (!seq.empty()) {
                        startPlayback = true;
                        playing       = true;
                    }
                    drawUI();
                    drawSeqUI();
                    continue;
                }

                if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
                    if (!seq.empty()) seq.pop_back();
                } else if (ch >= 32 && ch <= 126) {
                    seq.push_back(static_cast<char>(ch));
                }
            }

            drawUI();
            drawSeqUI();
        }

        if (!main_running) break;
        if (!startPlayback || seq.empty()) {
            continue;
        }

        // ---- PLAYBACK PHASE ---- //

        rideOn        = rideEnabled;
        padOn         = padEnabled;
        patternSelect = padPattern;
        breakName     = breakNames[breakIndex];
        padName       = padNames[padIndex];

        // semitone offset -> pitch factor
        pad_pitch = std::pow(2.0, padPitchSemis / 12.0);

        result = soundInit(engine, breakz, breakName, pad, padName, rideOn, ride);
        if (result != 0) {
            continue;
        }

        if (padOn)  ma_sound_set_volume(&pad, float(0.5 * masterVol));
        if (rideOn) ma_sound_set_volume(&ride, float(3.0 * masterVol));

        if (padOn)  ma_sound_set_pitch(&pad, pad_pitch);
        if (padOn)  ma_sound_get_length_in_pcm_frames(&pad, &pad_length);
        ma_sound_get_length_in_pcm_frames(&breakz, &drums_length);

        if (breakName == "Think Break") {
            ma_sound_set_volume(&breakz, float(masterVol * 4));
        } else {
            ma_sound_set_volume(&breakz, float(masterVol));
        }

        double quarter_ms = 60000.0 / tempo;
        double eighth_ms  = quarter_ms / 2.0;

        auto nextTick = clock::now();

        int breakBars = breaks[breakName];

        int padCountMax      = 1;
        int padPitchCountMax = 32;
        int padPitchCount    = 0;
        int rideCountMax     = 4;
        int rideCount        = 0;
        int padCount         = 0;

        double breakSecs  = double(drums_length) / double(sampleRate);
        double breakBpm   = 1 / (breakSecs / (breakBars * 4) / 60);
        double drum_pitch = double(tempo) / breakBpm;

        if (padOn)  ma_sound_set_pitch(&pad, pad_pitch * pitches[patternSelect][padPitchCount]);
        if (padOn)  ma_sound_start(&pad);
        if (rideOn) ma_sound_start(&ride);

        auto advanceCounter = [&]() {
            if (padCount == 0) {
                if (padOn) { ma_sound_seek_to_pcm_frame(&pad, 0); }
            }
            if (rideCount == 0) {
                if (rideOn) { ma_sound_seek_to_pcm_frame(&ride, 0); }
                if (padOn) {
                    ma_sound_set_pitch(&pad, pad_pitch * pitches[patternSelect][padPitchCount]);
                    double padPitchFactor = pad_pitch * pitches[patternSelect][padPitchCount];
                    double padSecs = double(pad_length) / double(sampleRate) / padPitchFactor;
                    double eighthSecs = 60.0 / (tempo * 2.0);
                    double maxEighthsReal = padSecs / eighthSecs;
                    int maxEighths = (int)maxEighthsReal;
                    padCountMax = 1;
                    while ((padCountMax * 2) <= maxEighths) {
                        padCountMax *= 2;
                    }
                    if (padCountMax < 1) { padCountMax = 1; }
                }
                padPitchCount = (padPitchCount + 1) % padPitchCountMax;
            }
            rideCount = (rideCount + 1) % rideCountMax;
            padCount  = (padCount  + 1) % padCountMax;
        };

        auto advanceTime = [&]() {
            nextTick += std::chrono::duration_cast<clock::duration>(
                            std::chrono::duration<double, std::milli>(eighth_ms));
            std::this_thread::sleep_until(nextTick);
        };

        playback_running = true;
        playing          = true;

        nodelay(stdscr, TRUE); // non-blocking input during playback

        while (playback_running && main_running) {
            for (int i = 0; i < (int)seq.size() && playback_running && main_running; ++i) {
                // highlight current character
                drawSeqPlayback(i);

                int key = getch();
                if (key == 27) {
                    playback_running = false;
                    main_running     = false;
                    break;
                } else if (key == '\n' || key == KEY_ENTER || key == '\r') {
                    playback_running = false;
                    break;
                }

                unsigned char c = static_cast<unsigned char>(seq[i]);
                auto [index, noteVal, pitch] = decode(c, breakBars);

                int gridDivisions = breakBars * 8;
                ma_uint64 PCMIndex = drums_length * index / gridDivisions;

                if (pitch == 0x0)      ma_sound_set_pitch(&breakz, drum_pitch);
                else if (pitch == 0x1) ma_sound_set_pitch(&breakz, drum_pitch * 1.15);

                if (index == 0xFF) {
                    ma_sound_stop(&breakz);
                } else {
                    ma_sound_seek_to_pcm_frame(&breakz, PCMIndex);
                    ma_sound_start(&breakz);
                }

                if (noteVal == 0x2) {
                    advanceCounter();
                    advanceTime();
                } else if (noteVal == 0x3) {
                    advanceCounter();
                    advanceTime();
                    advanceCounter();
                    advanceTime();
                } else if (noteVal == 0x1) {
                    advanceCounter();
                    advanceTime();
                    advanceCounter();
                    advanceTime();
                    advanceCounter();
                    advanceTime();
                } else if (noteVal == 0x0) {
                    advanceCounter();
                    nextTick += std::chrono::duration_cast<clock::duration>(
                                    std::chrono::duration<double, std::milli>(eighth_ms / 2.0));
                    std::this_thread::sleep_until(nextTick);
                    ma_sound_seek_to_pcm_frame(&breakz, PCMIndex);
                    ma_sound_start(&breakz);
                    nextTick += std::chrono::duration_cast<clock::duration>(
                                    std::chrono::duration<double, std::milli>(eighth_ms / 2.0));
                    std::this_thread::sleep_until(nextTick);
                }
            }
        }

        nodelay(stdscr, FALSE);

        if (padOn)  { ma_sound_stop(&pad); }
        if (rideOn) { ma_sound_stop(&ride); }
        ma_sound_stop(&breakz);

        if (padOn)  { ma_sound_uninit(&pad); }
        if (rideOn) { ma_sound_uninit(&ride); }
        ma_sound_uninit(&breakz);

        drawUI();
        drawSeqUI();
    }

    // --------- CLEANUP ---------- //
    delwin(seqWin);
    delwin(win);
    endwin();

    ma_engine_uninit(&engine);

    return 0;
}
