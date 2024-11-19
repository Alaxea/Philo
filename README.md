## Philosophers

![dinner](https://th.bing.com/th/id/OIP.ETzLMOCaL7Rvg2wqbgiQzwHaHe?pid=ImgDet&w=178&h=179&c=7&dpr=1,5)

### Problem statement
The Dining Philosopher Problem involves ‘n’ philosophers sitting around a circular table. Each philosopher alternates between three states: thinking, sleeping and eating. To eat, a philosopher needs two forks, one on their left and one on their right. However, the number of forks is equal to the number of philosophers, and each fork is shared between two neighboring philosophers.

### Constraints and Conditions for the Problem
-  The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
-  There are as many forks as philosophers.
-  Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
-   When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.

> [!IMPORTANT]
> Philosophers don’t speak with each other.

### Usage
```
git clone git@github.com:Alaxea/Philo.git
cd philo
make && ./philo [arguments]
```

### Conclusion 
The Dining Philosopher Problem is a great way to understand how to manage shared resources in a system while avoiding problems like deadlock and starvation. It shows how these issues can arise and teaches us how to prevent them by using the right synchronization techniques. Through learning about this, I also got familiar with concepts like mutexes, semaphores, and threads. These are important tools that help control access to resources and ensure that multiple processes can run smoothly without interfering with each other.
