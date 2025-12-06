import matplotlib.font_manager as fm
for f in fm.findSystemFonts():
    if "xkcd" in f.lower() or "humor" in f.lower():
        print(f)
