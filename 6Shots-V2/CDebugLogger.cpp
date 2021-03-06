#include "stdafx.h"
#include "CDebugLogger.h"

CDebugLogger::CDebugLogger() {
	/* Default to fatal, error & warning */
	m_iVerbosityFlags = LOGLEVEL_FATAL | LOGLEVEL_ERROR | LOGLEVEL_WARNING;

	m_bFile = false;
	m_sLogFile = "";

	/* Default print to stdout */
	m_bStdout = true;
	m_bLoggingEnabled = true;

	/* Default disable loglevel printing*/
	m_bPrintLogLevel = false;

	m_eLastLogLevel = LOGLEVEL_WARNING;
}

// Named-Parameter idiom	
CDebugLogger* CDebugLogger::LogLevel(ELoggingLevel level) {
	m_eLastLogLevel = level;
	return this;
}

void CDebugLogger::Log(const std::string& sOutput) {
	if (!m_bLoggingEnabled)
		return;
	if (m_bFile) {
		std::ofstream fstream(m_sLogFile, std::ios::binary);

		if (!fstream.good()) {
			m_bFile = false;
			Log("DbgLog - Unable to write to file " + m_sLogFile);
		} else {
			fstream << sOutput;
		}

		fstream.close();
	}
	if (m_bStdout) {
		fputs(sOutput.c_str(), stdout);
	}
}
void CDebugLogger::Log(char* format, ...) {
	if (!m_bLoggingEnabled)
		return;

	// Write formatted string
	char logOutputBuf[512];	
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);
	if (result <= 0) {
		LogWarning("Debug message skipped -> Exceeded 512 char limit\n");
		return;
	} 

	/* Handle file logging */
	if (m_bFile) {
		std::ofstream fstream(m_sLogFile);

		if (!fstream.good()) {
			m_bFile = false;
			Log("DbgLog - Unable to write to file " + m_sLogFile);
		} else {
			fstream.write(logOutputBuf, result);
		}
		
		fstream.close();
	}

	if (m_bStdout) {
		fputs(logOutputBuf, stdout);
	}
}

void CDebugLogger::Msg(const std::string& sOut, bool bAddNewline) {
	Instance()->LogLevel(LOGLEVEL_DEBUG)->Log(sOut + (bAddNewline ? "\n" : ""));
}
void CDebugLogger::Info(const std::string& sOut, bool bAddNewline) {
	Instance()->LogLevel(LOGLEVEL_DEBUG)->Log(sOut + (bAddNewline ? "\n" : ""));
}
void CDebugLogger::Warn(const std::string& sOut, bool bAddNewline) {
	Instance()->LogLevel(LOGLEVEL_DEBUG)->Log(sOut + (bAddNewline ? "\n" : ""));
}
void CDebugLogger::Error(const std::string& sOut, bool bAddNewline) {
	Instance()->LogLevel(LOGLEVEL_DEBUG)->Log(sOut + (bAddNewline ? "\n" : ""));
}
void CDebugLogger::Fatal(const std::string& sOut, bool bAddNewline) {
	Instance()->LogLevel(LOGLEVEL_DEBUG)->Log(sOut + (bAddNewline ? "\n" : ""));
}

void CDebugLogger::LogDebug(char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Set debug logging mode */
	Instance()->LogLevel();

	/* Log debug string */
	Instance()->Log(logOutputBuf);
}
void CDebugLogger::LogInfo(char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Set info logging mode */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_INFO);

	/* Log debug string */
	Instance()->Log(logOutputBuf);
}
void CDebugLogger::LogWarning(char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Set warning logging mode */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_WARNING);

	/* Log debug string */
	Instance()->Log(logOutputBuf);
}
void CDebugLogger::LogError(char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Set error logging mode */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_ERROR);

	/* Log debug string */
	Instance()->Log(logOutputBuf);
}
void CDebugLogger::LogFatal(char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Set fatal logging mode */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_FATAL);

	/* Log debug string */
	Instance()->Log(logOutputBuf);
}
void CDebugLogger::LogErrorFile(char* szFile, char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);
	
	/* Store previous settings */
	std::string logfile = Instance()->GetLogFile();
	bool bFileEnabled = Instance()->GetUseFile();

	/* Set logging mode, change file */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_ERROR);
	Instance()->SetLogFile(szFile);
	Instance()->SetUseFile(true);

	/* Log debug string */
	Instance()->Log(logOutputBuf);

	/* Restore settings */
	Instance()->SetLogFile((char*)logfile.c_str());
	Instance()->SetUseFile(bFileEnabled);
}
void CDebugLogger::LogFatalFile(char* szFile, char* format, ...) {
	/* Write formatted string */
	char logOutputBuf[512];
	va_list args;
	va_start(args, format);
	int result = vsprintf_s(logOutputBuf, 512, format, args);
	va_end(args);

	/* Store previous settings */
	std::string logfile = Instance()->GetLogFile();
	bool bFileEnabled = Instance()->GetUseFile();

	/* Set fatal logging mode */
	Instance()->LogLevel(CDebugLogger::LOGLEVEL_FATAL);
	Instance()->SetLogFile(szFile);
	Instance()->SetUseFile(true);

	/* Log debug string */
	Instance()->Log(logOutputBuf);

	/* Restore settings */
	Instance()->SetLogFile((char*)logfile.c_str());
	Instance()->SetUseFile(bFileEnabled);
}

CDebugLogger* CDebugLogger::SetVerbosityRange(ELoggingLevel Start, ELoggingLevel end) {
	if (Start >= LOGLEVEL_FATAL && end <= LOGLEVEL_FATAL)
		m_iVerbosityFlags |= LOGLEVEL_FATAL;
	if (Start >= LOGLEVEL_ERROR && end <= LOGLEVEL_ERROR)
		m_iVerbosityFlags |= LOGLEVEL_ERROR;
	if (Start >= LOGLEVEL_WARNING && end <= LOGLEVEL_WARNING)
		m_iVerbosityFlags |= LOGLEVEL_WARNING;
	if (Start >= LOGLEVEL_INFO && end <= LOGLEVEL_INFO)
		m_iVerbosityFlags |= LOGLEVEL_INFO;
	if (Start >= LOGLEVEL_DEBUG && end <= LOGLEVEL_DEBUG)
		m_iVerbosityFlags |= LOGLEVEL_DEBUG;
	return this;
}

CDebugLogger* CDebugLogger::SetVerbosityFlag(ELoggingLevel level, bool bEnabled) {
	if (bEnabled) m_iVerbosityFlags |= level;
	else m_iVerbosityFlags &= ~level;
	return this;
}

CDebugLogger* CDebugLogger::SetLogFile(char* szLogFile, bool bEnableFile) {
	m_sLogFile = szLogFile;
	m_bFile = bEnableFile;
	return this;
}

CDebugLogger* CDebugLogger::SetUseStdout(bool bEnable) {
	m_bStdout = bEnable;
	return this;
}

CDebugLogger* CDebugLogger::SetUseFile(bool bEnable) {
	m_bFile = bEnable;
	return this;
}

CDebugLogger* CDebugLogger::SetLogEnabled(bool bEnable) {
	m_bLoggingEnabled = bEnable;
	return this;
}