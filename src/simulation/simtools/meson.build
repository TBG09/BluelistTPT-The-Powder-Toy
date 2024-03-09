simulation_tool_ids = [
	[ 'HEAT', 0 ],
	[ 'COOL', 1 ],
	[ 'AIR',  2 ],
	[ 'VAC',  3 ],
	[ 'PGRV', 4 ],
	[ 'NGRV', 5 ],
	[ 'MIX',  6 ],
	[ 'CYCL', 7 ],
	[ 'AMBM', 8 ],
	[ 'AMBP', 9 ],
	[ 'INHE', 10 ],
	[ 'INCO', 11 ],
	[ 'INAM', 12 ],
	[ 'INBM', 13 ],
	[ 'INAR', 14 ],
	[ 'INVC', 15 ],
]

simulation_tool_src = []
foreach tool_name_id : simulation_tool_ids
	simulation_tool_src += tool_name_id[0] + '.cpp'
endforeach
simulation_files += files(simulation_tool_src)
