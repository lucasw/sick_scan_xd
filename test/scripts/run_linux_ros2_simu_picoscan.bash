#!/bin/bash

# killall and cleanup after exit
function killall_cleanup()
{
  sleep 1 ; killall -SIGINT rviz2
  sleep 1 ; killall -SIGINT sick_generic_caller
  sleep 1 ; pkill -f multiscan_sopas_test_server.py
  sleep 1 ; pkill -f multiscan_pcap_player.py
  sleep 1 ; killall -9 rviz2
  sleep 1 ; killall -9 sick_generic_caller
}

# 
# Run sick_timtwo on ROS2-Linux
# 

pushd ../../../..
printf "\033c"
if [ -f /opt/ros/eloquent/setup.bash ] ; then source /opt/ros/eloquent/setup.bash ; fi
if [ -f /opt/ros/foxy/setup.bash     ] ; then source /opt/ros/foxy/setup.bash     ; fi
source ./install/setup.bash
killall_cleanup
sleep 1
rm -rf ~/.ros/log
sleep 1

# Run mrs100/timtwo emulator (sopas test server)
python3 ./src/sick_scan_xd/test/python/multiscan_sopas_test_server.py --tcp_port=2111 --cola_binary=0 --FREchoFilter=1 &
ros2 run rviz2 rviz2 -d ./src/sick_scan_xd/test/emulator/config/rviz2_cfg_picoscan_emu.rviz & 
sleep 1
ros2 run rviz2 rviz2 -d ./src/sick_scan_xd/test/emulator/config/rviz2_cfg_picoscan_emu_360.rviz & 
sleep 1

# Start sick_generic_caller with sick_timtwo
echo -e "run_lidar3d.bash: sick_scan sick_picoscan.launch.py ..."
ros2 launch sick_scan sick_picoscan.launch.py hostname:=127.0.0.1 udp_receiver_ip:="127.0.0.1" &
sleep 3 # read -p "Press ENTER to continue..."

# Play timtwo pcapng-files with picoscan (timtwo) msgpack-data, mix 30 and 60 degree segments
echo -e "\nPlaying pcapng-files to emulate picoscan...\n"
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230315-picoscan.pcapng --udp_port=2115 --repeat=1
echo -e "\nPlaying pcapng-files to emulate TiMTwo. Note: Start of UDP msgpacks in 20221010_timtwo.pcapng takes a while...\n"
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile4.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile6.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile3.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile7.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile2.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile8.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile5.pcapng --udp_port=2115 --repeat=1
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20230204_timtwo_v0.18.0_msgpack_profile1.pcapng --udp_port=2115 --repeat=1
echo -e "\nPlaying pcapng-files to emulate TiMTwo. Note: Start of UDP msgpacks in 20221010_timtwo.pcapng takes a while...\n"
python3 ./src/sick_scan_xd/test/python/multiscan_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20221010_timtwo.pcapng --udp_port=2115 --repeat=1
sleep 3

# Shutdown
echo -e "run_linux_ros2_simu_timtwo.bash finished, killing all processes ..."
killall_cleanup
popd
