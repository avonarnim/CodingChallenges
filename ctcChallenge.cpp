#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

class Task {
    public:
        Task(int ident, std::string desc, int teamIdent, std::string urgency) {
            id = ident;
            description = desc;
            teamID = teamIdent;
            priority = urgency;
        }

        std::string toString() const {
            std::string printable = std::to_string(this->id) + "/ " + this->description + "/ ";
            printable += std::to_string(this->teamID) + "/ " + this->priority;
            return printable;
        }
        std::string getPriority() const {
            return this->priority;
        }
        int getId() const {
            return this->id;
        }
        int getTeam() const {
            return this->teamID;
        }
    private:
        int id;
        std::string description;
        int teamID;
        std::string priority;
};

// Used to compare scchedules by priority if possible
class Compare1 {
    public:
        std::map<std::string, int> priorityMap = {
            {"HIGH", 2},
            {"MED", 1},
            {"LOW", 0}
        };
        bool operator()(const Task& lhs, const Task& rhs) {
            if (lhs.getPriority() != rhs.getPriority()) {
                return priorityMap[lhs.getPriority()] < priorityMap[rhs.getPriority()];
            } else {
                return lhs.getId() > rhs.getId();
            }
        };
};

// Used to schedule by ID only
class Compare2 {
    public:
        bool operator()(const Task& lhs, const Task& rhs) {
            return lhs.getId() > rhs.getId();
        };
};

class TaskStorage {
    public:
        // initialize object information
        TaskStorage(int teamInput, int sprintInput, int numInput) {
            teams = teamInput;
            weeks = sprintInput;
            numInput = numJobs;
            for (int i = 0; i < teams; i++) {
                std::priority_queue<Task, std::vector<Task>, Compare1> q;
                tasksByTeam.push_back(q);
            }
        }

        //assign a Task object to a team's priority queue
        void assignJob(Task input) {
            tasksByTeam[input.getTeam()].push(input);
            return;
        }

        void printAssignments() {
            std::priority_queue<Task, std::vector<Task>, Compare2> sprintSpecificSorter;
            std::string base;
            // printing schedulable tasks
            for (int i = 0; i < weeks; i++) {
                for (int j = 0; j < teams; j++) {
                    if (tasksByTeam[j].empty() != true) {
                        sprintSpecificSorter.push(tasksByTeam[j].top());
                        tasksByTeam[j].pop();
                    }
                }
                while (sprintSpecificSorter.empty() != true) {
                    base = sprintSpecificSorter.top().toString();
                    base += "/ " + std::to_string(i);
                    cout << base << endl;
                    sprintSpecificSorter.pop();
                }
            }
            // all schedulable tasks have been printed
            for (int i = 0; i < teams; i++) {
                while (tasksByTeam[i].empty() != true) {
                    sprintSpecificSorter.push(tasksByTeam[i].top());
                    tasksByTeam[i].pop();
                }
            }
            while (sprintSpecificSorter.empty() != true) {
                base = sprintSpecificSorter.top().toString();
                cout << base << endl;
                sprintSpecificSorter.pop();
            }
        }

        // returns the number of teams
        int getNumTeams() {
            return tasksByTeam.size();
        }

        // prints the number of tasks per team
        std::string getNumTasksByTeam() {
            cout << "getting num tasks by team" << endl;
            std::string counts= "";
            for (int i = 0; i < (int) tasksByTeam.size(); i++) {
                counts += std::to_string((int) tasksByTeam[i].size()) + " ";
            }
            return counts;
        }
        // prints all tasks by team
        void printAllTasks() {
            // This is used for testing purposes. Caution: it will pop all data
            for (int i = 0; i < (int) tasksByTeam.size(); i++) {
                cout << "Team " << std::to_string(i) << " has " << std::to_string(tasksByTeam[i].size()) << " tasks" << endl;
                int numTasksToPrint = (int) tasksByTeam[i].size();
                for (int j = 0; j < numTasksToPrint; j++) {
                    cout << tasksByTeam[i].top().toString() << endl;
                    tasksByTeam[i].pop();
                }
            }
        }

    private:
        int teams;
        int weeks;
        int numJobs;
        std::vector<std::priority_queue<Task, std::vector<Task>, Compare1> > tasksByTeam;

};

int main()
{
    int teams, sprints, jobs;
    std::string jobInput;
    int jobID, jobTeamID;
    std::string jobDescription, jobUrgency;
    std::string delimiter = "/ ";

    // cout << "Please enter all input data: ";
    cin >> teams >> sprints >> jobs;
    getline(std::cin, jobInput); // jobInput acts as a dummy to get rid of \n

    TaskStorage myStorage (teams, sprints, jobs);

    for (int i = 0; i < jobs; i++) {
        // retrieving input and splitting it by delimiter
        std::getline(std::cin, jobInput);
        jobID = std::stoi( jobInput.substr(0, jobInput.find(delimiter)) );
        jobInput = jobInput.substr(jobInput.find(delimiter)+2);
        jobDescription = jobInput.substr(0, jobInput.find(delimiter));
        jobInput = jobInput.substr(jobInput.find(delimiter)+2);
        jobTeamID = std::stoi( jobInput.substr(0, jobInput.find(delimiter)) );
        jobInput = jobInput.substr(jobInput.find(delimiter)+2);
        jobUrgency = jobInput.substr(0, jobInput.find(delimiter));

        Task temp(jobID, jobDescription, jobTeamID, jobUrgency);

        myStorage.assignJob(temp);
    }

    myStorage.printAssignments();

    return 0;
}
