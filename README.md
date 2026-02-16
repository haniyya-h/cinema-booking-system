# cinema-booking-system


**Cinema Booking System — ITP Semester 1 Final Project**

Overview
- A simple console-based Cinema Booking System written in C++ for an introductory ITP course final project. The program lets users view movies and showtimes, select seats, and save booking information to disk.

Table of contents
- Overview
- Requirements
- Build
- Run
- Usage
- Screenshots (where to add them)
- Project structure
- Contributing
- License & Contact

Requirements
- A C++ compiler that supports C++17 (g++, clang, or MSVC).
- Minimal disk space to store booking output in the `output/` folder.

Build
- Using `g++` (MinGW/MSYS2/WSL):

```bash
g++ -std=c++17 -O2 -o cinema main.cpp
```

- Using MSVC (Developer Command Prompt):

```powershell
cl /EHsc main.cpp
```

Run
- On Windows (when built with `g++`):

```powershell
.\cinema.exe
```

- On Linux/macOS/WSL:

```bash
./cinema
```

Usage
- After running the binary, follow the on-screen menu prompts to:
	- View currently available movies and showtimes
	- Select a showtime and seats
	- Confirm and save a booking (output files written to `output/`)

Screenshots — where to add them
- Recommended screenshots folder: `docs/screenshots` (create this folder at the project root).
- Suggested filenames: `booking-1.png`, `booking-2.png`, `seats-1.png`, etc.
- To include screenshots in this README, add the image files to `docs/screenshots` then insert links or Markdown image tags. Example Markdown:

```markdown
![Booking screen](docs/screenshots/booking-1.png)
```

- If you prefer the `output/` directory, you may also place images in `output/screenshots`, but `docs/screenshots` keeps documentation separate from runtime output.

Project structure
- [main.cpp](main.cpp) — program source (single-file console app).
- [README.md](README.md) — this file.
- `output/` — folder the program writes booking data into at runtime.

Contributing
- This is a student project. If you want to make improvements, consider:
	- Refactoring into multiple source files (separate UI, data, and persistence)
	- Adding unit tests
	- Adding input validation and error handling

Suggested local git steps before submitting

```bash
git add README.md docs/screenshots/*
git commit -m "Add complete README and screenshot guidance"
git push origin main
```

License & Contact
- Replace this section with your chosen license or keep it simple for course submission. For questions or assistance, add your name and email here.

If you want, I can also:
- create the `docs/screenshots` folder and add a placeholder image file
- make the git commit and push to your remote (I will need your confirmation and remote configured)

Screenshot headings (add the images with these filenames in `docs/screenshots`):

- **Welcome / Movies display**

	![Welcome / Movies display](<img width="598" height="280" alt="image" src="https://github.com/user-attachments/assets/eadf8a73-0baf-4b44-861e-0e6cbfd9e783" />
)

- **Showtime selection screen**

	![Showtime selection screen](<img width="313" height="185" alt="image" src="https://github.com/user-attachments/assets/f06a4c1a-83c1-40d7-8785-9feb79e43cbf" />
)

- **Menu Display**

	![Menu Display](<img width="297" height="181" alt="image" src="https://github.com/user-attachments/assets/ba93da49-a43f-4933-b7fe-0c08760442f9" />
)

- **Seat Layout showing available seats**

	![Seat Layout showing available seats](<img width="409" height="185" alt="image" src="https://github.com/user-attachments/assets/02e0b544-c828-4500-b821-7adb0a315907" />
)

- **Booking confirmation messages**

	![Booking confirmation messages]<img width="415" height="487" alt="image" src="https://github.com/user-attachments/assets/2b0cdc13-7f23-485e-88d4-6067af1758db" />
)

- **Receipt generation**

	![Receipt generation](<img width="487" height="478" alt="image" src="https://github.com/user-attachments/assets/b96c4e1f-94c2-417b-84e8-969122c0744c" />
)

