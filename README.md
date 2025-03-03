<div align="center">
  <a href="https://github.com/mpeyre-s/42_philosophers"><img src="https://github.com/mpeyre-s/42_project_badges/raw/main/badges/philosophers.svg"/></a>
  <p>The aim of this project is to create a simulation of the Dining Philosophers problem, providing a fundamental understanding of concurrency, threading, and synchronization mechanisms.</p>
  <br>
</div>

# ➡️ Competencies Acquired

- **Concurrency**: Learned how to manage multiple threads and synchronize their actions to avoid race conditions and deadlocks.

- **Threading**: Gained hands-on experience with thread creation, management, and termination using the pthread library.

- **Synchronization**: Implemented mutexes and condition variables to control access to shared resources and ensure proper synchronization between threads.

- **Error Handling**: Strengthened debugging skills by implementing robust error checking and handling edge cases in a multi-threaded environment.

- **Memory Management**: Applied best practices for memory allocation and deallocation to avoid leaks and ensure stability.

- **Team Collaboration**: Collaborated with peers using Git, improving teamwork and version control skills.

# ➡️ Program Features

1. **Philosopher Simulation**:
   - Simulates the behavior of philosophers who alternate between eating, thinking, and sleeping.
   - Each philosopher is represented by a separate thread.

2. **Concurrency Control**:
   - Uses mutexes to ensure that only one philosopher can access a fork at a time.
   - Implements condition variables to manage the state transitions of philosophers (e.g., from thinking to eating).

3. **Deadlock Prevention**:
   - Ensures that the simulation does not enter a deadlock state by implementing proper locking and unlocking mechanisms.
   - Implements strategies to avoid circular wait and other deadlock conditions.

4. **Error Handling**:
   - Provides descriptive error messages for thread creation failures, synchronization issues, and other runtime errors.
   - Robust handling of edge cases, such as improper input values or unexpected thread terminations.

# ➡️ Project Insights

- **Challenges Faced**:
  - Ensuring proper synchronization between threads to avoid race conditions and deadlocks.
  - Managing the complexity of concurrent programming and debugging multi-threaded applications.
  - Implementing a robust and efficient algorithm to simulate the dining philosophers problem.

- **Lessons Learned**:
  - The importance of careful design and planning in concurrent programming.
  - The need for thorough testing and debugging to identify and fix synchronization issues.
  - The value of modular code and clear function responsibilities in managing complexity.
