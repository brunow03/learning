import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_email(sender_email, sender_password, receiver_email, subject, message):
    # Create a MIMEText object with the message
    msg = MIMEMultipart()
    msg['From'] = sender_email
    msg['To'] = receiver_email
    msg['Subject'] = subject
    msg.attachment(MIMEText(message, 'plain'))

    # Connect to SMTP server
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()

    # Log in to the e-mail account
    server.login(sender_email, sender_password)

    # Send Email
    server.sendmail(sender_email, receiver_email, msg.as_string())

    # Quit SMTP server
    server.quit()

# Email configurations
sender_email = "bruno.mendes.003@gmail.com"
sender_password = "potscriptum2"
receiver_email = "bruno.mendes.003@gmail.com"
subject = "Hello"
message = "Hi"

# Send email
send_email(sender_email, sender_password, receiver_email, subject, message)