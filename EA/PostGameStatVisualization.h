#ifndef POSTGAMESTATVISUALIZATION_H
#define POSTGAMESTATVISUALIZATION_H

#include<string>
#include<vector>

class Team;

class PostGameStatsScreen{
    private:
        TeamStatsPanel* team_stats_panel;
        PlayerHighlightsPanel* player_highlights_panel;
        HeatMapPanel* heat_map_panel;
        DriveTrackerPanel* drive_tracker_panel;

    public:
        void toggle_view_mode();
        void navigate_to_panel(int panelId);

};

class TeamStatsPanel{
    private:
        Team* team_a;
        Team* team_b;
    public:
        void renderBarGraphs();
};

class Team{
    private:
        std::string team_name;
        std::vector<Player*> players;

    public:
        void calculateTeamStats();
        std::string getTeamName() const;
        void setTeamName(const std::string& name);
        const std::vector<Player*>& getPlayers() const;
        void addPlayer(Player* player);
};

class Player{
    private:
        std::string name;
        std::string position;
        std::vector<float> stats;
    public:
        void calculatePerformanceMetrics();
        std::string getName() const;
        void setName(const std::string& name);
        std::string getPosition() const;
        void setPosition(const std::string& position);
        const std::vector<float>& getStats() const;
        void addStat(float stat);

};

class HeatMapPanel{
    public:
        void calculateHeatZones();
};

class DriveTrackerPanel{
    public:
        renderTimeline();
};

class Drive{
    private:
        std::vector<Play*> plays;
    public:
        void summarizeDrive();
        const std::vector<Play*>& getPlays() const;
        void addPlay(Play* play);
};

class Play{
    private:
        std::string play_type;
        int yardage;
    public:
        float getPlayEffectiveness();
        std::string getPlayType() const;
        void setPlayType(const std::string& type);
        int getYardage() const;
        void setYardAge(int yards);
};

#endif