import subprocess

FFMPEG = r"ffmpeg-9.0.2-essentials_build\bin\ffmpeg.exe"
SECONDS = 36000  # 5-minute test; later 36000 for 10 hours

drawtext = (
    r"drawtext=fontfile='C\:/Windows/Fonts/arial.ttf':"
    r"text='%{eif\:trunc((SECS-t)/3600)\:d\:2}"
    r"\:%{eif\:trunc(mod(SECS-t\,3600)/60)\:d\:2}"
    r"\:%{eif\:mod(SECS-t\,60)\:d\:2}':"
    r"fontsize=200:fontcolor=white:x=(w-text_w)/2:y=(h-text_h)/2"
).replace("SECS", str(SECONDS))

subprocess.run(
    [
        FFMPEG,
        "-y",
        "-f",
        "lavfi",
        "-i",
        f"color=c=black:s=1920x1080:r=1:d={SECONDS + 1}",
        "-vf",
        drawtext,
        "-c:v",
        "libx264",
        "-pix_fmt",
        "yuv420p",
        "-g",
        "1",
        "-movflags",
        "+faststart",
        "countdown.mp4",
    ]
)
