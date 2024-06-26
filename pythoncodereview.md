```python
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
```
```python
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

```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp_microsecond to datetime
process_data['timestamp_datetime'] = pd.to_datetime(process_data['timestamp_microsecond'] / 1000, unit='us')

# Plot process average time based on Item_Number
process_avg_time = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp_datetime']].groupby('Item_Number').agg({'timestamp_datetime': ['min', 'max']}).apply(lambda x: (x['timestamp_datetime']['max'] - x['timestamp_datetime']['min']) / pd.Timedelta(seconds=1), axis=1)

plt.figure(figsize=(10, 6))
process_avg_time.plot(kind='bar', rot=0)
plt.title('Process Average Time based on Item_Number')
plt.xlabel('Item Number')
plt.ylabel('Time (seconds)')
plt.tight_layout()
plt.savefig('Process_Average.png')
plt.show()

# Calculate process average time for each Item_Number vs time elapsed
time_elapsed = process_data['timestamp_datetime'].max() - process_data['timestamp_datetime'].min()
process_avg_time_vs_time_elapsed = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp_datetime']].groupby('Item_Number').apply(lambda x: (x['timestamp_datetime'].max() - x['timestamp_datetime'].min()) / time_elapsed)

print('Process Average Time for each Item_Number vs Time Elapsed:')
print(process_avg_time_vs_time_elapsed)


# # Calculate process average time for each Item_Number
# process_avg_time = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp']].groupby('Item_Number').agg({'timestamp': ['max', 'min']}).apply(lambda x: x['timestamp']['max'] - x['timestamp']['min'], axis=1)

# # Calculate time elapsed for each Item_Number
# time_elapsed = process_data.groupby('Item_Number')['timestamp'].agg(['max', 'min']).apply(lambda x: x['max'] - x['min'], axis=1)

# # Combine the results into a DataFrame
# results_df = pd.DataFrame({'Process Average Time': process_avg_time, 'Time Elapsed': time_elapsed})

# # Save the results to a CSV file
# results_df.to_csv('process_time_results2.csv', index_label='Item_Number')

# # Plot the process average time vs time elapsed
# plt.figure(figsize=(10, 6))
# plt.scatter(time_elapsed, process_avg_time, s=50)
# plt.xlabel('Time Elapsed (microseconds)')
# plt.ylabel('Process Average Time (microseconds)')
# plt.title('Process Average Time vs Time Elapsed')
# plt.tight_layout()
# plt.savefig('Process_Average_Time2.png')
# plt.show()

# # # Calculate process average time for each Item_Number
# # process_avg_time = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp_microsecond']].groupby('Item_Number').agg({'timestamp_microsecond': ['max', 'min']}).apply(lambda x: x['timestamp_microsecond']['max'] - x['timestamp_microsecond']['min'], axis=1)

# # # Calculate time elapsed for each Item_Number
# # time_elapsed = process_data.groupby('Item_Number')['timestamp_microsecond'].agg(['max', 'min']).apply(lambda x: x['max'] - x['min'], axis=1)

# # # Plot the process average time vs time elapsed
# # plt.figure(figsize=(10, 6))
# # plt.scatter(time_elapsed, process_avg_time, s=50)
# # plt.xlabel('Time Elapsed (microseconds)')
# # plt.ylabel('Process Average Time (microseconds)')
# # plt.title('Process Average Time vs Time Elapsed')
# # plt.tight_layout()
# # plt.show()

df = pd.DataFrame(process_data)

# Save the DataFrame to a CSV file
csv_filename = 'data.csv'
df.to_csv(csv_filename, index=False)
print(f"Data saved to '{csv_filename}'")
```
```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

#df = pd.DataFrame(process_data)

# Save the DataFrame to a CSV file
# csv_filename = 'data.csv'
# process_data.to_csv(csv_filename, index=False)
# print(f"Data saved to '{csv_filename}'")

# Convert timestamp_microsecond to datetime
#process_data['timestamp_datetime'] = pd.to_datetime(process_data['timestamp_microsecond'] / 1000, unit='us')
#################################################################################################################################
# # Convert the 'timestamp' column to datetime format
process_data['timestamp'] = pd.to_datetime(process_data['timestamp'], format='%H:%M:%S.%f')
####################################Plot process average time based on Item_Number working###################################
# # Plot process average time based on Item_Number
# process_avg_time = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp']].groupby('Item_Number').agg({'timestamp': ['min', 'max']}).apply(lambda x: (x['timestamp']['max'] - x['timestamp']['min']) / pd.Timedelta(seconds=1), axis=1)

# # Convert process_avg_time to a DataFrame
# process_avg_time_df = process_avg_time.reset_index()
# process_avg_time_df.columns = ['Item_Number', 'Average_Time_Seconds']
# # Save the results to a CSV file
# process_avg_time_df.to_csv('Process_Average_Time.csv', index=False)

# plt.figure(figsize=(10, 6))
# process_avg_time.plot(kind='bar', rot=0)
# plt.title('Process Average Time based on Item_Number')
# plt.xlabel('Item Number')
# plt.ylabel('Time (seconds)')
# plt.tight_layout()
# plt.savefig('Process_Average_time.png')
# plt.show()

# # Calculate process average time for each Item_Number vs time elapsed
# time_elapsed = process_data['timestamp_datetime'].max() - process_data['timestamp_datetime'].min()
# process_avg_time_vs_time_elapsed = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'timestamp_datetime']].groupby('Item_Number').apply(lambda x: (x['timestamp_datetime'].max() - x['timestamp_datetime'].min()) / time_elapsed)

# print('Process Average Time for each Item_Number vs Time Elapsed:')
# print(process_avg_time_vs_time_elapsed)


##Calculate the time taken to process each item

# # Calculate the time taken to process each item
# process_time = process_data.groupby('Item_Number').agg({'timestamp': ['min', 'max']})
# process_time.columns = ['start_time', 'end_time']
# process_time['time_taken'] = (process_time['end_time'] - process_time['start_time']).dt.total_seconds()

# # Plot the average time taken for each item number
# plt.figure(figsize=(10, 6))
# process_time['time_taken'].plot(kind='bar', rot=0)
# plt.title('Average Time Taken to Process Each Item Number')
# plt.xlabel('Item Number')
# plt.ylabel('Time Taken (seconds)')
# plt.tight_layout()
# #plt.savefig('Avg_Time_Taken_Per_Item.png')
# plt.show()

###########################Fail####Calculate process average time for each Item_Number vs time elapsed from above################################################
# # Calculate the elapsed time from the start
# start_time = process_data['timestamp'].min()
# process_data['time_elapsed'] = (process_data['timestamp'] - start_time).dt.total_seconds()

# # Calculate process average time for each Item_Number
# process_avg_time = process_data.loc[(process_data['record_position'] >= 1) & (process_data['record_position'] <= 3), ['Item_Number', 'time_elapsed', 'timestamp']].groupby(['Item_Number', 'time_elapsed']).agg({'timestamp': ['min', 'max']}).apply(lambda x: (x['timestamp']['max'] - x['timestamp']['min']).total_seconds(), axis=1)

# # Convert process_avg_time to a DataFrame
# process_avg_time_df = process_avg_time.reset_index()
# process_avg_time_df.columns = ['Item_Number', 'Time_Elapsed', 'Average_Time_Seconds']

# # Save the results to a CSV file
# process_avg_time_df.to_csv('Process_Average_Time_vs_Time_Elapsed.csv', index=False)

# # Plot the results
# plt.figure(figsize=(10, 6))
# for item_number in process_avg_time_df['Item_Number'].unique():
#     subset = process_avg_time_df[process_avg_time_df['Item_Number'] == item_number]
#     plt.plot(subset['Time_Elapsed'], subset['Average_Time_Seconds'], label=f'Item {item_number}')

# plt.title('Process Average Time vs Time Elapsed for Each Item_Number')
# plt.xlabel('Time Elapsed (seconds)')
# plt.ylabel('Average Time (seconds)')
# plt.legend()
# plt.tight_layout()
# #plt.savefig('Process_Average_Time_vs_Time_Elapsed.png')
# plt.show()
##########plot Total_item elapsed over time######working###############################
# Calculate the elapsed time from the start
# start_time = process_data['timestamp'].min()
# process_data['time_elapsed'] = (process_data['timestamp'] - start_time).dt.total_seconds()

# # Save the results to a CSV file
# process_data.to_csv('Total_item_vs_Time_Elapsed.csv', index=False)

# # Plot the Total_item vs time elapsed
# plt.figure(figsize=(10, 6))
# plt.plot(process_data['time_elapsed'], process_data['Total_item'], marker='o')
# plt.title('Total Item Count vs Time Elapsed')
# plt.xlabel('Time Elapsed (seconds)')
# plt.ylabel('Total Item Count')
# plt.grid(True)
# plt.tight_layout()
# plt.savefig('Total_Item_vs_Time_Elapsed.png')
# plt.show()

##############################plot the average record position (from 1 to 3) for each item number over time#### not working

# # Calculate the elapsed time from the start
# start_time = process_data['timestamp'].min()
# process_data['time_elapsed'] = (process_data['timestamp'] - start_time).dt.total_seconds()

# # Calculate the average record position for each item number over time
# avg_record_position = process_data.groupby(['time_elapsed', 'Item_Number'])['record_position'].mean().reset_index()

# # Save the results to a CSV file
# avg_record_position.to_csv('Avg_Record_Position_vs_Time_Elapsed.csv', index=False)

# # Plot the average record position over time for each item number
# plt.figure(figsize=(12, 8))
# for item in avg_record_position['Item_Number'].unique():
#     subset = avg_record_position[avg_record_position['Item_Number'] == item]
#     plt.plot(subset['time_elapsed'], subset['record_position'], marker='o', label=f'Item {item}')

# plt.title('Average Record Position (1 to 3) Over Time for Each Item Number')
# plt.xlabel('Time Elapsed (seconds)')
# plt.ylabel('Average Record Position')
# plt.legend(title='Item Number')
# plt.grid(True)
# plt.tight_layout()
# plt.savefig('Avg_Record_Position_vs_Time_Elapsed.png')
# plt.show()

###########To plot the average record position (from 1 to 3) over time mark each item on the plot

# # Calculate the elapsed time from the start
# start_time = process_data['timestamp'].min()
# process_data['time_elapsed'] = (process_data['timestamp'] - start_time).dt.total_seconds()

# # Calculate the average record position for each item number over time
# avg_record_position = process_data.groupby(['time_elapsed', 'Item_Number'])['record_position'].mean().reset_index()

# # Save the results to a CSV file
# avg_record_position.to_csv('Avg_Record_Position_vs_Time_Elapsed.csv', index=False)

# # Plot the average record position over time for each item number and mark each item on the plot
# plt.figure(figsize=(12, 8))
# for item in avg_record_position['Item_Number'].unique():
#     subset = avg_record_position[avg_record_position['Item_Number'] == item]
#     plt.plot(subset['time_elapsed'], subset['record_position'], marker='o', label=f'Item {item}')
#     for i in range(len(subset)):
#         plt.text(subset['time_elapsed'].iloc[i], subset['record_position'].iloc[i], f'{subset["Item_Number"].iloc[i]}', fontsize=8, ha='right')

# plt.title('Average Record Position (1 to 3) Over Time for Each Item Number')
# plt.xlabel('Time Elapsed (seconds)')
# plt.ylabel('Average Record Position')
# plt.legend(title='Item Number')
# plt.grid(True)
# plt.tight_layout()
# #plt.savefig('Avg_Record_Position_vs_Time_Elapsed.png')
# plt.show()

####################################position 1 to 3 for each Item_Number

# Calculate the time it took from record position 1 to 3 for each Item_Number
time_diff = process_data.pivot_table(index='Item_Number', columns='record_position', values='timestamp', aggfunc='first')
time_diff['time_from_1_to_3'] = (time_diff[3] - time_diff[1]).dt.total_seconds()

# Calculate elapsed time from the first timestamp
process_data = process_data.sort_values(by='timestamp')
process_data['elapsed_time'] = (process_data['timestamp'] - process_data['timestamp'].iloc[0]).dt.total_seconds()

# Merge the elapsed time back to the time_diff dataframe
item_first_timestamp = process_data.drop_duplicates(subset='Item_Number', keep='first')[['Item_Number', 'elapsed_time']]
time_diff = time_diff.merge(item_first_timestamp, on='Item_Number')

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(time_diff['elapsed_time'], time_diff['time_from_1_to_3'], marker='o')
for i, txt in enumerate(time_diff.index):
    plt.annotate(txt, (time_diff['elapsed_time'][i], time_diff['time_from_1_to_3'][i]), textcoords="offset points", xytext=(5,-5), ha='center')

plt.title('Time from Record Position 1 to 3 vs Elapsed Time')
plt.xlabel('Elapsed Time (seconds)')
plt.ylabel('Time from Position 1 to 3 (seconds)')
plt.tight_layout()
#plt.savefig('Time_from_1_to_3_vs_Elapsed_Time.png')
plt.show()

# Save processed data to CSV
#process_data.to_csv('processed_data.csv', index=False)
# Save selected columns to CSV
time_diff[['elapsed_time', 'time_from_1_to_3']].to_csv('time_diff_processed.csv', index=False)
```

```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process',   'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert the 'timestamp' column to datetime format
process_data['timestamp'] = pd.to_datetime(process_data['timestamp'], format='%H:%M:%S.%f')

# Calculate the time it took from record position 1 to 3 for each Item_Number
time_diff = process_data.pivot_table(index='Item_Number', columns='record_position', values='timestamp', aggfunc='first')
time_diff['time_from_1_to_3'] = (time_diff[3] - time_diff[1]).dt.total_seconds()

# Calculate elapsed time from the first timestamp
process_data = process_data.sort_values(by='timestamp')
process_data['elapsed_time'] = (process_data['timestamp'] - process_data['timestamp'].iloc[0]).dt.total_seconds()

# Merge the elapsed time back to the time_diff dataframe
item_first_timestamp = process_data.drop_duplicates(subset='Item_Number', keep='first')[['Item_Number', 'elapsed_time']]
time_diff = time_diff.merge(item_first_timestamp, on='Item_Number')

# Record the average time from record position 1 to 3 for each timestamp
average_time = process_data.groupby('timestamp')['time_from_1_to_3'].mean().reset_index()

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(average_time['timestamp'], average_time['time_from_1_to_3'], marker='o')
plt.title('Average Time from Record Position 1 to 3 Over Time')
plt.xlabel('Timestamp')
plt.ylabel('Average Time from Position 1 to 3 (seconds)')
plt.tight_layout()
plt.show()

```
```python

import pandas as pd

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp to datetime
process_data['timestamp'] = pd.to_datetime(process_data['timestamp'], format='%H:%M:%S.%f')

# Create a new DataFrame to store the filtered data
filtered_df = pd.DataFrame(columns=['timestamp_microsecond', 'timestamp', 'Item_Number', 'name', 'record_position', 'Total_item'])

# Initialize variables to keep track of the last record_position and Item_Number
last_record_position = 0
last_item_number = None

# Iterate over each row in the original DataFrame
for index, row in process_data.iterrows():
    if row['Item_Number'] != last_item_number:
        last_record_position = 0
        last_item_number = row['Item_Number']

    if row['record_position'] == 1 and last_record_position == 0:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 1
    elif row['record_position'] == 3 and last_record_position == 1:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 3

# Save the filtered DataFrame to a CSV file
filtered_df.to_csv('filtered_data3.csv', index=False)

##############

import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
})

# Convert timestamp to datetime
process_data['timestamp'] = pd.to_datetime(process_data['timestamp'], format='%H:%M:%S.%f')

# Create a new DataFrame to store the result
result_df = pd.DataFrame(columns=['start_time', 'end_time', 'time_difference', 'real_minute', 'minute_from_zero'])

# Find the start and end times for each segment
start_times = process_data[process_data['record_position'] == 1]['timestamp']
end_times = process_data[process_data['record_position'] == 3]['timestamp']

# Get the initial minute value
initial_minute = start_times.iloc[0].minute

# Calculate the time difference for each segment
for start_time, end_time in zip(start_times, end_times):
    time_diff = (end_time - start_time).total_seconds()
    real_minute = start_time.minute
    minute_from_zero = real_minute - initial_minute
    result_df = pd.concat([result_df, pd.DataFrame({'start_time': [start_time],
                                                    'end_time': [end_time],
                                                    'time_difference': [time_diff],
                                                    'real_minute': [real_minute],
                                                    'minute_from_zero': [minute_from_zero]})], ignore_index=True)

# Plot the time difference against the timestamp
plt.figure(figsize=(10, 6))
plt.scatter(result_df['start_time'], result_df['time_difference'], marker='o', color='blue')
plt.xlabel('Timestamp')
plt.ylabel('Time Difference (seconds)')
plt.title('Time Difference vs Timestamp')
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Save the result DataFrame to a CSV file
result_df.to_csv('time_differences3.csv', index=False)
```
```python
import pandas as pd
import matplotlib.pyplot as plt

def load_data():
    return pd.DataFrame({
        'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
        'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
        'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
        'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
        'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
        'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
    })

def preprocess_data(data):
    data['timestamp'] = pd.to_datetime(data['timestamp'], format='%H:%M:%S.%f')
    return data

def calculate_time_differences(data):
    result_df = pd.DataFrame(columns=['start_time', 'end_time', 'time_difference', 'real_minute', 'minute_from_zero'])

    start_time = None
    initial_minute = None

    for _, row in data.iterrows():
        if row['record_position'] == 1:
            start_time = row['timestamp']
            if initial_minute is None:
                initial_minute = start_time.minute
        elif row['record_position'] == 3:
            end_time = row['timestamp']
            time_diff = (end_time - start_time).total_seconds()
            real_minute = start_time.minute
            minute_from_zero = real_minute - initial_minute
            result_df = pd.concat([result_df, pd.DataFrame({'start_time': [start_time],
                                                            'end_time': [end_time],
                                                            'time_difference': [time_diff],
                                                            'real_minute': [real_minute],
                                                            'minute_from_zero': [minute_from_zero]})], ignore_index=True)

    return result_df

def plot_time_differences(result_df):
    plt.figure(figsize=(10, 6))
    plt.scatter(result_df['start_time'], result_df['time_difference'], marker='o', color='blue')
    plt.xlabel('Timestamp')
    plt.ylabel('Time Difference (seconds)')
    plt.title('Time Difference vs Timestamp')
    plt.grid(True)
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()

def save_result_to_csv(result_df, filename):
    result_df.to_csv(filename, index=False)

def main():
    data = load_data()
    data = preprocess_data(data)
    result_df = calculate_time_differences(data)
    plot_time_differences(result_df)
    save_result_to_csv(result_df, 'time_differences.csv')

if __name__ == '__main__':
    main()
```

Sure, here is the refactored code that ignores the date in the `timestamp` column and then calculates the time difference between record positions 1 and 3 for each `Item_Number`:

```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
process_data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'timestamp': ['20:46:47.307000', '20:46:47.348000', '20:46:47.389000', '20:46:47.471000', '20:46:47.512000', '20:46:47.553000', '20:46:47.594000', '20:46:47.676000', '20:46:47.717000', '20:46:47.758000', '20:46:47.799000', '20:46:47.881000', '20:46:47.922000', '20:46:47.963000', '20:46:48.004000', '20:46:48.045000', '20:46:48.086000', '20:46:48.127000', '20:46:48.168000', '20:46:48.250000', '20:46:48.291000', '20:46:48.332000', '20:46:48.373000', '20:46:48.414000', '20:46:48.455000', '20:46:48.496000', '20:46:48.578000', '20:46:48.619000', '20:46:48.660000', '20:46:48.701000', '20:46:48.742000', '20:46:48.783000', '20:46:48.824000', '20:46:48.865000'],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp to datetime, ignoring the date
process_data['timestamp'] = pd.to_datetime(process_data['timestamp'], format='%H:%M:%S.%f').dt.time

# Convert the time to timedelta for easier manipulation
process_data['timestamp'] = process_data['timestamp'].apply(lambda x: pd.to_timedelta(f"{x.hour}:{x.minute}:{x.second}.{x.microsecond}"))

# Create a new DataFrame to store the filtered data
filtered_df = pd.DataFrame(columns=['timestamp_microsecond', 'timestamp', 'Item_Number', 'name', 'record_position', 'Total_item'])

# Initialize variables to keep track of the last record_position and Item_Number
last_record_position = 0
last_item_number = None

# Iterate over each row in the original DataFrame
for index, row in process_data.iterrows():
    if row['Item_Number'] != last_item_number:
        last_record_position = 0
        last_item_number = row['Item_Number']

    if row['record_position'] == 1 and last_record_position == 0:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 1
    elif row['record_position'] == 3 and last_record_position == 1:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 3

# Create a new DataFrame to store the result
result_df = pd.DataFrame(columns=['start_time', 'end_time', 'time_difference', 'real_minute', 'minute_from_zero'])

# Find the start and end times for each segment
start_times = filtered_df[filtered_df['record_position'] == 1]['timestamp']
end_times = filtered_df[filtered_df['record_position'] == 3]['timestamp']

# Get the initial minute value
initial_minute = start_times.iloc[0].components.minutes

# Calculate the time difference for each segment
for start_time, end_time in zip(start_times, end_times):
    time_diff = (end_time - start_time).total_seconds()
    real_minute = start_time.components.minutes
    minute_from_zero = real_minute - initial_minute
    result_df = pd.concat([result_df, pd.DataFrame({'start_time': [start_time],
                                                    'end_time': [end_time],
                                                    'time_difference': [time_diff],
                                                    'real_minute': [real_minute],
                                                    'minute_from_zero': [minute_from_zero]})], ignore_index=True)

# Plot the time difference against the timestamp
plt.figure(figsize=(10, 6))
plt.scatter(result_df['start_time'].apply(lambda x: x.total_seconds()), result_df['time_difference'], marker='o', color='blue')
plt.xlabel('Timestamp (seconds)')
plt.ylabel('Time Difference (seconds)')
plt.title('Time Difference vs Timestamp')
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Save the result DataFrame to a CSV file
result_df.to_csv('time_differences.csv', index=False)
```
```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'Item_Number': [6000, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp_microsecond to datetime format
data['timestamp'] = pd.to_datetime(data['timestamp_microsecond'], unit='us')
#print(data['timestamp'])

# Create a new DataFrame with the specified columns from the data DataFrame
filtered_df = pd.DataFrame({
    'timestamp': data['timestamp'],
    'Item_Number': data['Item_Number'],
    'name': data['name'],
    'record_position': data['record_position'],
    'Total_item': data['Total_item']
})

# Save the result DataFrame to a CSV file
filtered_df.to_csv('filtered_df.csv', index=False)

# Initialize variables to keep track of the last record_position and Item_Number
last_record_position = 0
last_item_number = None

result_df = pd.DataFrame(columns=['start_time', 'end_time', 'time_difference', 'real_minute', 'minute_from_zero'])

start_time = None
initial_minute = None

for _, row in data.iterrows():
    if row['record_position'] == 1 and last_record_position == 0:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 1
        start_time = row['timestamp']

        if initial_minute is None:
            initial_minute = start_time.minute
    elif row['record_position'] == 3 and last_record_position == 1:
        filtered_df = pd.concat([filtered_df, row.to_frame().T], ignore_index=True)
        last_record_position = 3

        end_time = row['timestamp']
        time_diff = (end_time - start_time).total_seconds()
        real_minute = start_time.minute
        minute_from_zero = real_minute - initial_minute
        result_df = pd.concat([result_df, pd.DataFrame({'start_time': [start_time],
                                                        'end_time': [end_time],
                                                        'time_difference': [time_diff],
                                                        'real_minute': [real_minute],
                                                        'minute_from_zero': [minute_from_zero]})], ignore_index=True)

# Plot the time difference against every minute
plt.figure(figsize=(10, 6))
plt.scatter(result_df['start_time'], result_df['time_difference'], marker='o', color='blue')
plt.xlabel('Timestamp')
plt.ylabel('Time Difference (seconds)')
plt.title('Time Difference vs Timestamp')
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Save the result DataFrame to a CSV file
result_df.to_csv('time_differences.csv', index=False)
```

```python
import pandas as pd
import matplotlib.pyplot as plt

# Load the data into a DataFrame
data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'Item_Number': [0, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp_microsecond to datetime format
data['timestamp'] = pd.to_datetime(data['timestamp_microsecond'], unit='us')
data['timestamp'] = data['timestamp'] - data['timestamp'].min()  # to start from zero

# Filter the data
filtered_df = data[(data['record_position'] == 1) | (data['record_position'] == 3)]
filtered_df = filtered_df.reset_index(drop=True)  # Reset index for convenience



# Load the data into a DataFrame
data2 = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'Item_Number': [0, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp_microsecond to datetime format
data2['timestamp'] = pd.to_datetime(data2['timestamp_microsecond'], unit='us')
data2['timestamp'] = data2['timestamp'] - data2['timestamp'].min()  # to start from zero


# Filter the data
filtered_df2 = data2[(data2['record_position'] == 1) | (data2['record_position'] == 3)]
filtered_df2 = filtered_df2.reset_index(drop=True)  # Reset index for convenience

# Initialize result DataFrame
result_df = pd.DataFrame(columns=filtered_df.columns)
result_df2 = pd.DataFrame(columns=filtered_df.columns)

# Initialize variables to keep track of the last record_position
last_record_position = 0

start_record_position = 1
end_record_position = 3

# Process the filtered DataFrame
for _, row in filtered_df.iterrows():
    if row['record_position'] == start_record_position and last_record_position != start_record_position:
        start_time = row['timestamp']
        result_df = pd.concat([result_df, row.to_frame().T], ignore_index=True)
        last_record_position = start_record_position

    elif row['record_position'] == end_record_position and last_record_position == start_record_position:
        last_record_position = 0

# Process the filtered DataFrame
for _, row in filtered_df2.iterrows():
    if row['record_position'] == start_record_position and last_record_position != start_record_position:
        last_record_position = start_record_position

    elif row['record_position'] == end_record_position and last_record_position == start_record_position:
        end_time = row['timestamp']
        result_df2 = pd.concat([result_df, row.to_frame().T], ignore_index=True)
        last_record_position = 0


# Save the result DataFrame to a CSV file
result_df.to_csv('result_df.csv', index=False)
result_df2.to_csv('result_df2.csv', index=False)






# # Optionally, plot the results
# plt.figure(figsize=(12, 6))
# plt.plot(result_df['timestamp'], result_df['Item_Number'], marker='o')
# plt.xlabel('Timestamp')
# plt.ylabel('Item Number')
# plt.title('Filtered Items Over Time')
# plt.grid(True)
# plt.show()

#print(filtered_df)
# Save the result DataFrame to a CSV file
#filtered_df.to_csv('filtered_df.csv', index=False)

# Initialize variables to keep track of the last record_position and Item_Number
# last_record_position = 0
# last_item_number = None

# start_record_position = 1
# end_record_position = 3

# Identify sequences of 1 followed by 3.
# Ignore any subsequent 1s until a 3 is found.
# Reset the tracking variables after a 1-3 sequence is found.


# # Process the filtered DataFrame
# for _, row in filtered_df.iterrows():
#     if row['record_position'] == start_record_position and last_record_position == 0:
#         result_df = pd.concat([result_df, row.to_frame().T], ignore_index=True)
#         last_record_position = start_record_position
#         #last_item_number = row['Item_Number']
#     elif row['record_position'] == end_record_position and last_record_position == start_record_position: #and row['Item_Number'] == last_item_number:
#         result_df = pd.concat([result_df, row.to_frame().T], ignore_index=True)
#         last_record_position = end_record_position
#         #last_item_number = None

import pandas as pd
import matplotlib.pyplot as plt

# Load the data into DataFrames
data = pd.DataFrame({
    'timestamp_microsecond': [1716407307000, 1716407348000, 1716407389000, 1716407471000, 1716407512000, 1716407553000, 1716407594000, 1716407676000, 1716407717000, 1716407758000, 1716407799000, 1716407881000, 1716407922000, 1716407963000, 1716408004000, 1716408045000, 1716408086000, 1716408127000, 1716408168000, 1716408250000, 1716408291000, 1716408332000, 1716408373000, 1716408414000, 1716408455000, 1716408496000, 1716408578000, 1716408619000, 1716408660000, 1716408701000, 1716408742000, 1716408783000, 1716408824000, 1716408865000],
    'Item_Number': [0, 6000, 6000, 6001, 6001, 6001, 6001, 6000, 6000, 6000, 6000, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6001, 6002, 6002, 6002, 6002, 6002, 6002, 6002, 6003, 6003, 6003, 6003, 6003, 6003, 6003, 6003],
    'name': ['Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process', 'Process'],
    'record_position': [1, 1, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 1, 2, 1, 2, 1, 2, 3, 2, 1, 2, 2, 1, 2, 3, 1, 2, 2, 1, 2, 1, 2, 3],
    'Total_item': [1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3]
})

# Convert timestamp_microsecond to datetime format
data['timestamp'] = pd.to_datetime(data['timestamp_microsecond'], unit='us')
data['timestamp'] = data['timestamp'] - data['timestamp'].min()  # to start from zero

# Filter the data
filtered_df = data[(data['record_position'] == 1) | (data['record_position'] == 3)]
filtered_df = filtered_df.reset_index(drop=True)  # Reset index for convenience

# Initialize result DataFrames
result_df = pd.DataFrame(columns=filtered_df.columns)

# Initialize variables to keep track of the last record_position
last_record_position = 0

start_record_position = 1
end_record_position = 3

# Process the filtered DataFrame
for _, row in filtered_df.iterrows():
    if row['record_position'] == start_record_position and last_record_position != start_record_position:
        start_time = row['timestamp']
        result_df = pd.concat([result_df, row.to_frame().T], ignore_index=True)
        last_record_position = start_record_position

    elif row['record_position'] == end_record_position and last_record_position == start_record_position:
        end_time = row['timestamp']
        result_df = pd.concat([result_df, row.to_frame().T], ignore_index=True)
        last_record_position = 0

# Repeat the same steps for data2
data2 = data.copy()  # Assuming data2 is similar to data
data2['timestamp'] = pd.to_datetime(data2['timestamp_microsecond'], unit='us')
data2['timestamp'] = data2['timestamp'] - data2['timestamp'].min()

filtered_df2 = data2[(data2['record_position'] == 1) | (data2['record_position'] == 3)]
filtered_df2 = filtered_df2.reset_index(drop=True)

result_df2 = pd.DataFrame(columns=filtered_df2.columns)
last_record_position = 0

for _, row in filtered_df2.iterrows():
    if row['record_position'] == start_record_position and last_record_position != start_record_position:
        start_time = row['timestamp']
        result_df2 = pd.concat([result_df2, row.to_frame().T], ignore_index=True)
        last_record_position = start_record_position

    elif row['record_position'] == end_record_position and last_record_position == start_record_position:
        end_time = row['timestamp']
        result_df2 = pd.concat([result_df2, row.to_frame().T], ignore_index=True)
        last_record_position = 0

# Save the result DataFrames to CSV files
result_df.to_csv('result_df.csv', index=False)
result_df2.to_csv('result_df2.csv', index=False)

# # Optionally, plot the results
# plt.figure(figsize=(12, 6))
# plt.plot(result_df['timestamp'], result_df['Item_Number'], marker='o', label='Data 1')
# plt.plot(result_df2['timestamp'], result_df2['Item_Number'], marker='x', label='Data 2')
# plt.xlabel('Timestamp')
# plt.ylabel('Item Number')
# plt.title('Filtered Items Over Time')
# plt.legend()
# plt.grid(True)
# plt.show()


```
```python
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime, timedelta

# Create process timestamps and duration timestamps
process_timestamps = []
duration_timestamps = []

start_time = datetime(2023, 1, 1, 0, 0, 0)  # Starting time for the process

for i in range(10):
    process_time = start_time + timedelta(minutes=i * 5)  # Increment process time by 5 minutes
    process_timestamp = process_time.strftime("%M:%S.%f")[:-4]  # Format process timestamp as "mm:sec.f"
    process_timestamps.append(process_timestamp)
    
    duration = timedelta(hours=i, minutes=i * 2, seconds=i * 3)  # Create duration timestamp
    duration_timestamp = str(duration)  # Format duration timestamp as "hh::mm::ss"
    duration_timestamps.append(duration_timestamp)

# Create a pandas DataFrame
data = {
    'Process Timestamp': process_timestamps,
    'Duration Timestamp': duration_timestamps
}
df = pd.DataFrame(data)

# Save the DataFrame as a CSV file
df.to_csv('timestamps.csv', index=False)

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(process_timestamps, duration_timestamps, marker='o')
plt.xlabel('Process Timestamp')
plt.ylabel('Duration Timestamp')
plt.title('Process vs Duration')
plt.xticks(rotation=45)
plt.grid(True)
plt.tight_layout()
plt.show()

```
