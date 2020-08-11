# IoT_ping-pong
An IoT project for Hive's ping pong table. The goal of this project is to let players keep track of their games, by simply scanning their student ID card with a RFID scanner. The score will be uploaded and players can keep track of their game stats.

## Design

### Stats
Calculated on backend

- Win %
- Win count
- Loss count
- Longest win streak
- Longest loss streak (vtran)

### Filters
Database might become so big so it might be also best to do these in backend

- Player 1
- Player 2
- Last N games
- Time e.g last week

### Authentication
Needed for admin-features. Everyone should be able to see stats, but games can be
only added via IoT-device or admin rights.

### Edge cases
- Card changes
- Piscine ID / Student ID

### Device
- Show error if no internet connection
- Show error if server is down

### Database
- TODO

### Quick example data
```go
type Stats struct {
	Wins             int     `json:"wins"`
	Losses           int     `json:"losses"`
	Games            int     `json:"games"`
	WinPercentage    float64 `json:"winPercentage"`
	HighestWinStreak int     `json:"highestWinStreak"`
	CurrentWinStreak int     `json:"currentWinStreak"`
}

// This will be sended to client
map[playerName] = Stat{}
```

## Contributors:

[Miikka Tuominen](https://github.com/tuommii)<br>
[Rasmus Jaakonmäki](https://github.com/rasmusjaa)<br>
[Tuomas Louekari](https://github.com/ninjapiraatti)<br>
[Vesa Kuokka](https://github.com/vkuokka)
