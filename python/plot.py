import matplotlib.pyplot as plt

# Points to plot
x_values = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24]
y_values = [1, 1, 4, 15, 56, 210, 792, 3003, 11440, 43758, 167960, 646646, 2496144]

# Plot the points
plt.figure(figsize=(10, 6))
plt.plot(x_values, y_values, marker='o', linestyle='-', color='b', label='Points')

# Add labels and title
plt.title('Points on Cartesian Plane', fontsize=14)
plt.xlabel('x-axis', fontsize=12)
plt.ylabel('y-axis', fontsize=12)
 # Use a logarithmic scale for better visualization of large values
plt.grid(True, which="both", linestyle='--', linewidth=0.5)
plt.legend()
plt.show()
