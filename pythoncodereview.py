# import pandas as pd
# import matplotlib.pyplot as plt
# from datetime import timedelta

# # Load the data from the CSV file
# filename = "vehicle_data.csv"
# data = pd.read_csv(filename)

# # Handle the scientific notation in timestamps (if any)
# data['Timestamp (microseconds)'] = data['Timestamp (microseconds)'].apply(lambda x: int(float(x)))

# # Convert the timestamp from microseconds to seconds for readability
# data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# # Calculate the duration each vehicle count lasted
# data['Duration (seconds)'] = data['Timestamp (seconds)'].diff().fillna(0)

# # Remove the initial row since its duration is 0 and not meaningful
# data = data.iloc[1:]

# # Convert durations to human-readable format (hours, minutes, seconds)
# data['Duration (readable)'] = data['Duration (seconds)'].apply(lambda x: str(timedelta(seconds=x)))

# # Plot the data
# plt.figure(figsize=(10, 6))
# plt.bar(data['Vehicle Count'], data['Duration (seconds)'], color='b')

# # Add labels and title
# plt.xlabel('Vehicle Count')
# plt.ylabel('Duration (seconds)')
# plt.title('Duration Each Vehicle Count Lasted')
# plt.grid(True)

# # Save the plot to a file
# # plot_filename = 'vehicle_duration_plot.png'
# # plt.savefig(plot_filename)
# # print(f"Plot saved as '{plot_filename}'")
# # Show the plot
# plt.show()

# # Display the plot (optional)
# # plt.show()  # Uncomment this line if you want to display the plot interactively

# # Print the data for reference
# print(data[['Vehicle Count', 'Duration (readable)']])


import pandas as pd
import matplotlib.pyplot as plt
from datetime import timedelta

# Load the data from the CSV file
filename = "plotdata2.csv"
data = pd.read_csv(filename)

# Handle the scientific notation in timestamps (if any)
data['Timestamp (microseconds)'] = data['Timestamp (microseconds)'].apply(lambda x: int(float(x)))

# Convert the timestamp from microseconds to seconds for readability
data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# Calculate the duration each vehicle number was recorded
# Find the time differences where vehicle number changes
data['Duration (seconds)'] = data['Timestamp (seconds)'].diff().fillna(0)

# Group by vehicle number and sum the durations
durations = data.groupby('Vehicle')['Duration (seconds)'].sum().reset_index()

# Convert durations to human-readable format (hours, minutes, seconds)
durations['Duration (readable)'] = durations['Duration (seconds)'].apply(lambda x: str(timedelta(seconds=x)))

# Plot the data
plt.figure(figsize=(10, 6))
plt.bar(durations['Vehicle'], durations['Duration (seconds)'], color='b')

# Add labels and title
plt.xlabel('Vehicle Number')
plt.ylabel('Duration (seconds)')
plt.title('Duration Each Vehicle Number Was Recorded')
plt.grid(True)

# Save the plot to a file
# plot_filename = 'vehicle_duration_plot.png'
# plt.savefig(plot_filename)
# print(f"Plot saved as '{plot_filename}'")

# Display the plot (optional)
plt.show()  # Uncomment this line if you want to display the plot interactively

# Print the data for reference
print(durations[['Vehicle', 'Duration (readable)']])


```python
import pandas as pd
import matplotlib.pyplot as plt
from datetime import timedelta

# Load the data from the CSV file
filename = "vehicle_data.csv"
data = pd.read_csv(filename)

# Handle the scientific notation in timestamps (if any)
data['Timestamp (microseconds)'] = data['Timestamp (microseconds)'].apply(lambda x: int(float(x)))

# Convert the timestamp from microseconds to seconds for readability
data['Timestamp (seconds)'] = data['Timestamp (microseconds)'] / 1e6

# Calculate the duration each vehicle number was recorded
# Find the time differences where vehicle number changes
data['Duration (seconds)'] = data['Timestamp (seconds)'].diff().fillna(0)

# Group by vehicle number and sum the durations
durations = data.groupby('Vehicle numbr')['Duration (seconds)'].sum().reset_index()

# Convert durations to human-readable format (hours, minutes, seconds)
durations['Duration (readable)'] = durations['Duration (seconds)'].apply(lambda x: str(timedelta(seconds=x)))

# Plot the data
plt.figure(figsize=(10, 6))
plt.bar(durations['Vehicle numbr'], durations['Duration (seconds)'], color='b')

# Add labels and title
plt.xlabel('Vehicle Number')
plt.ylabel('Duration (seconds)')
plt.title('Duration Each Vehicle Number Was Recorded')
plt.grid(True)

# Ensure only the present vehicle numbers are shown on the x-axis
plt.xticks(durations['Vehicle numbr'])

# Save the plot to a file
plot_filename = 'vehicle_duration_plot.png'
plt.savefig(plot_filename)
print(f"Plot saved as '{plot_filename}'")

# Display the plot (optional)
plt.show()  # Uncomment this line if you want to display the plot interactively

# Print the data for reference
print(durations[['Vehicle numbr', 'Duration (readable)']])


```
```python
import random
import csv
from datetime import datetime, timedelta

# Function to generate random times
def generate_random_times(count):
    base_time = datetime.now()
    return [(base_time + timedelta(seconds=i)).strftime("%H:%M:%S.%f") for i in range(count)]

# Function to generate random average process times
def generate_random_process_times(count):
    return [round(random.uniform(0.1, 5.0), 3) for i in range(count)]

# Generate sample data
time_list = generate_random_times(100)
process_time_list = generate_random_process_times(100)

# Combine the data into a list of dictionaries
sample_data = [{"Time": t, "Average Process Time": pt} for t, pt in zip(time_list, process_time_list)]

# Define the CSV file name
csv_file = "sample_data.csv"

# Write the sample data to the CSV file
with open(csv_file, mode='w', newline='') as file:
    writer = csv.DictWriter(file, fieldnames=["Time", "Average Process Time"])
    writer.writeheader()
    writer.writerows(sample_data)

print(f"Sample data has been exported to {csv_file}")

```
