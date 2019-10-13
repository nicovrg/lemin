#!/usr/bin/python
	
def play_pause(animation, anim_running):
	if anim_running:
		animation.event_source.stop()
		anim_running = False
	else:
		animation.event_source.start()
		anim_running = True
	return anim_running

def switch_background(theme):
	if theme["background_color"] == "#15202B":
		theme["background_color"] = "#1515B6"
	elif theme["background_color"] == "#1515B6":
		theme["background_color"] = "#15B6B6"
	elif theme["background_color"] == "#15B6B6":
		theme["background_color"] = "#6615B6"
	elif theme["background_color"] == "#6615B6":
		theme["background_color"] = "#B61566"
		
		
		# theme["background_color"] = "#B615B6"
		# theme["background_color"] = "#B61566"
	
	
	# elif theme["background_color"] == "":
	# elif theme["background_color"] == "":
	# elif theme["background_color"] == "":
	# elif theme["background_color"] == "":
	# elif theme["background_color"] == "":



	# elif theme["background_color"] == "#15B6B6":
	# 	theme["background_color"] = "#15B615"
	# elif theme["background_color"] == "#15B6B6":
	# 	theme["background_color"] = "#B61515"
	# elif theme["background_color"] == "#B61515":
	# 	theme["background_color"] = "#B66615"
	# elif theme["background_color"] == "#B66615":
	# 	theme["background_color"] = "#B6B615"

	# elif theme["background_color"] == "":




	return theme
